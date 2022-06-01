#include <stdlib.h>
#include <unistd.h>
#include "./get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main (int argc, char **argv)
{
	int	fd;

	fd = 0;
	if (argc <= 1)
		return 0;
	fd = open(argv[1], 0);
	get_next_line(fd);
	return (0);
}