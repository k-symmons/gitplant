#include <linux/limits.h>
#include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>


typedef struct {
	size_t commits;
	size_t points;
	time_t last_commit;
	time_t now;
}t_save;

int get_path(char *data_path)
{
	const char *xdg_home;
	const char *home;

	xdg_home = getenv("XDG_DATA_HOME");

	if (xdg_home != NULL && *xdg_home != '\0')
		snprintf(data_path, PATH_MAX, "%s/gitplant", xdg_home);
	else
	{
		home = getenv("HOME");
		if (home == NULL)
			return (-1);
		snprintf(data_path, PATH_MAX, "%s/.local/share/gitplant", home);
	}
	return (0);
}


int count_commit(char *data_path)
{
	int fd;
	char buf[1024];
	ssize_t n;
	char logpath[4096];
	int count = 0;

	strcpy(logpath, data_path);
	strcat(logpath, "/events.txt");

	fd = open(logpath, O_RDONLY);
	if(fd == -1)
		return ( 0);
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



int main()
{
	char data_path[PATH_MAX];
	get_path(data_path);
	t_save save;
	save.commits = count_commit(data_path);

	printf("%zu", save.commits);
}
