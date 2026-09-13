#include <linux/limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>


typedef struct {
	size_t commits;
	size_t points;
	time_t last_commit;
	time_t now;
}t_save;

// I know I should not use PATH_MAX like an ape, but im too lazy to fix this
typedef struct
{
	char data_path[PATH_MAX];
	char log_path[PATH_MAX];
	char save_path[PATH_MAX];
}t_paths;

// function to get where to put save files
int get_path(t_paths *paths)
{
	const char *xdg_home;
	const char *home;

	xdg_home = getenv("XDG_DATA_HOME");

	if (xdg_home != NULL && *xdg_home != '\0')
		snprintf(paths->data_path, PATH_MAX, "%s/gitplant", xdg_home);
	else
	{
		home = getenv("HOME");
		if (home == NULL)
			return (-1);
		snprintf(paths->data_path, PATH_MAX, "%s/.local/share/gitplant", home);
	}
	return (0);
}

void get_log_path(t_paths *paths)
{
	strcpy(paths->log_path, paths->data_path);
	strcat(paths->log_path, "/events.txt");
}

void get_save_path(t_paths *paths)
{
	strcpy(paths->save_path, paths->data_path);
	strcat(paths->save_path, "/save.txt");
}



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
		return (0);
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


/* time_t get_commit_time(char , int commit_line) */
/* { */
/* 	while(commit_line) */
/* 	{ */

/* 	} */
/* } */


int main()
{
	t_save save;
	t_paths paths;
	get_path(&paths);
	get_log_path(&paths);
	get_save_path(&paths);
	save.commits = count_commit(&paths);
	save.now = time(NULL);

	printf("%s\n", paths.data_path);
	printf("%s\n", paths.save_path);
	printf("%s\n", paths.log_path);

	printf("%zu\n", save.commits);
	printf("%jd\n", (intmax_t)save.now);
}
