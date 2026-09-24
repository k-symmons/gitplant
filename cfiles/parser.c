# include "plant.h"

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
