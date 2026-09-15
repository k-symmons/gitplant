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

#endif
