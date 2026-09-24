#include "plant.h"
int main()
{
	t_save save;
	t_paths paths;
	get_path(&paths);
	get_log_path(&paths);
	get_save_path(&paths);

	int multi_base = 20;
	int multi_24h = 10;
	int c_24h_sec = 86400;


	read_save(&paths, &save);
	draw_plant(save.points / 1000);

	while (1)
	{
		save.now = time(NULL);
		read_save(&paths, &save);
		int log_commit_count = count_commit(&paths);
		if((int)save.commits < log_commit_count)
		{
			int log_last_commit = get_commit_time(&paths, log_commit_count);
			if (log_last_commit - save.last_commit > c_24h_sec)
				save.points += (log_commit_count-save.commits) *multi_base * multi_24h;
			else
				save.points += (log_commit_count-save.commits) *multi_base;
			// bug: if the newest commit is older than 24h compared to save.last_commit, all commits after last commits get multi_24h
			save.commits = log_commit_count;
			save.last_commit = log_last_commit;
			draw_plant(save.points / 1000);
		}
		write_save(&paths, &save);
		sleep(300);
	}
}
