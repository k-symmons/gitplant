#include "plant.h"
void stoa_helper(char *string, long long num, ssize_t i, ssize_t len)
{
	char c;
	if (num > 9)
		stoa_helper(string, num/10, i+1, len);
	c = num % 10 + '0';
	string[len-i-1] = c;
}

char *stoa(long long num)
{
	long long digit = 1;
	int digit_count = 0;
	char *string;

	if (num != 0)
	{
		while(num/digit > 0)
		{
			digit_count++;
			digit *= 10;
		}
	}
	else
		digit_count = 0;

	string = calloc(digit_count +2, sizeof(char));

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
	n = write(fd,buf, (strlen(buf) + 1));
	if(n == -1)
		printf("failed to write event file");
	close(fd);
}
