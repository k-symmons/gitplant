#include "plant.h"

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
	commit_line --;

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
