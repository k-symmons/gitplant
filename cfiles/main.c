#include "plant.h"
int main()
{
	t_save save;
	t_paths paths;
	get_path(&paths);
	get_log_path(&paths);
	get_save_path(&paths);

	int multi_base = 10;
	int multi_24h = 10;
	int c_24h_sec = 86400;


	read_save(&paths, &save);
	draw_progress(save.points);
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
				save.points += (log_commit_count-save.commits-1) *multi_base + (multi_base * multi_24h); //after 24h newest commit get a aditional multi
			else
				save.points += (log_commit_count-save.commits) *multi_base;
			save.commits = log_commit_count;
			save.last_commit = log_last_commit;
			draw_progress(save.points);
			draw_plant(save.points / 1000);
		}
		write_save(&paths, &save);
		sleep(5);
	}
}
