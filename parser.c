# include <stdio.h>
# include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char g_data_path[4096];

int get_path(void)
{
	const char *xdg_home;
	const char *home;

	xdg_home = getenv("XDG_DATA_HOME");

	if (xdg_home != NULL && *xdg_home != '\0')
		snprintf(g_data_path, sizeof(g_data_path), "%s/gitplant", xdg_home);
	else
	{
		home = getenv("HOME");
		if (home == NULL)
			return (-1);
		snprintf(g_data_path, sizeof(g_data_path), "%s/.local/share/gitplant", home);
	}
	return (0);
}


int count_commit()
{
	int fd;
	char buf[1024];
	ssize_t n;
	char logpath[4096];
	int count = 0;

	strcpy(logpath, g_data_path);
	strcat(logpath, "/events.txt");

	fd = open(logpath, O_RDONLY);
	if(fd == -1)
		return (close(fd), 0);
	while((n = read(fd,buf,sizeof(buf)-1) > 0))
	{
		int i = 0;
		while(buf[i] != '\0')
		{
			if (buf[i] == '\n')
				count ++;
			i ++;
		}
	}
	return (count);
}


int main()
{
	get_path();
	printf("%d", count_commit());
}
