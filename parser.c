# include "plant.h"
#include <string.h>



int count_commit(t_paths *paths)
{
	int fd;
	char buf[1024];
	ssize_t n;
	int count = 0;


	fd = open(paths->log_path, O_RDONLY);
	if(fd == -1)
	{
		printf("failed to read file\n");
		exit(1);
	}
	while((n = read(fd,buf,sizeof(buf))) > 0)
	{
		int i = 0;
		while(i < n)
		{
			if (buf[i] == '\n')
				count ++;
			i ++;
		}
	}
	close(fd);
	return (count);
}

// read 1 byte until it reaches the line I want to be on, then reads 1024 byts. Aweful implementation but its gonna do for now
time_t get_commit_time(t_paths *paths, int commit_line)
{
	time_t commit_time = 0;
	int fd;
	char buf[1024];
	ssize_t n;

	fd = open(paths->log_path, O_RDONLY);

	if(fd == -1)
	{
		printf("failed to open event file\n");
		exit(1);
	}
	n = read(fd,buf,sizeof(char));
	if(n == -1)
		printf("failed to read event file");
	while((n = read(fd,buf,sizeof(char))) > 0 && commit_line > 0)
	{
		if  (buf[0] == '\n')
			commit_line--;
	}
	read(fd,buf,sizeof(buf));
	int i = 0;
	while(buf[i] != ' ' && buf[i])
		i++;
	i++;
	commit_time = (time_t)strtol(&buf[i], NULL, 10);
	close(fd);
	return (commit_time);
}

void read_save(t_paths *paths, t_save *save)
{
	int fd;
	char buf[1024];
	int i = 0;
	ssize_t n;

	fd = open(paths->save_path, O_RDONLY);

	if(fd == -1)
	{
		printf("failed to open save file\n");
		exit(1);
	}
	n = read(fd,buf,sizeof(buf));
	if(n == -1)
		printf("failed to read event file");
	while(buf[i] != ':')
		i++;
	i++;
	save->commits = strtol(&buf[i], NULL, 10);
	while(buf[i] != ':')
		i++;
	i++;
	save->points = strtol(&buf[i], NULL, 10);
	while(buf[i] != ':')
		i++;
	i++;
	save->last_commit = (time_t)strtol(&buf[i], NULL, 10);
	close(fd);

}
void stoa_helper(char *string, ssize_t num, ssize_t i, ssize_t len)
{
	char c;
	if (num > 9)
		stoa_helper(string, num/10, i+1, len);
	c = num % 10 + '0';
	string[len-i-1] = c;
}

char *stoa(ssize_t num)
{
	int digit = 1;
	int digit_count = 0;
	char *string;



	while(num/digit > 0)
	{
		digit_count++;
		digit *= 10;
	}
	string = malloc(sizeof(char) * digit_count + 1);

	if(string == 0)
	{
		write(1, "fuck", 4); //todo think of a better error message
		exit(1);
	}

	if (num > 0)
	{
		stoa_helper(string, num, 0, digit_count);
		string[digit_count] = '\0';
	}
	else
	{
		strcat(string,"0");
	}
	return (string);

}

void write_save(t_paths *paths, t_save *save)
{
	int fd;
	char buf[1024] = "";
	ssize_t n;

	fd = open(paths->save_path, O_WRONLY | O_TRUNC);

	if(fd == -1)
	{
		printf("failed to open save file\n");
		exit(1);
	}
	strcat(buf,"commits:" );
	strcat(buf, stoa(save->commits));
	strcat(buf, "\npoints:");
	strcat(buf, stoa(save->points));
	strcat(buf, "\nlastcommit:");
	strcat(buf, stoa((ssize_t)save->last_commit));
	n = write(fd,buf,sizeof(buf));
	if(n == -1)
		printf("failed to write event file");
	close(fd);
}


int main()
{
	t_save save;
	t_paths paths;
	get_path(&paths);
	get_log_path(&paths);
	get_save_path(&paths);
	save.now = time(NULL);
	/* read_save(&paths, &save); */





	save.commits = count_commit(&paths);
	save.last_commit = get_commit_time(&paths, save.commits);
	save.points = 3;

	printf("%d\n", (int)save.commits);
	printf("%d\n", (int)save.last_commit);
	printf("%d\n", (int)save.points);
	write_save(&paths, &save);
}
