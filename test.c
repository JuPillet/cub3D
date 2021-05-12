#include "libft/libft.h"

int main(int ac, char **av)
{
	int fd;
	char *test;

	fd = open("settings/standard_setting.cub", O_RDONLY);
	get_next_line(fd, &test);
	close(fd);
	free(test);
	return (0);
}