#ifndef PLANT_H
# define PLANT_H


#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>


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


int get_path(t_paths *paths);
void get_log_path(t_paths *paths);
void get_save_path(t_paths *paths);
void write_save(t_paths *paths, t_save *save);
char *stoa(long long num);
void read_save(t_paths *paths, t_save *save);
time_t get_commit_time(t_paths *paths, int commit_line);
int count_commit(t_paths *paths);
void draw_plant(int lvl);

#endif
