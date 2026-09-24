# include "plant.h"

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
