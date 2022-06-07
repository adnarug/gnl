#include <stdlib.h>
#include <unistd.h>
#include "./get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main ()
{
	int	fd;

	fd = 0;
	fd = open("text", 0);
	printf ("next line: %s \n", get_next_line(fd));
	return (0);
}