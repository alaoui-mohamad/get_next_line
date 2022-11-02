

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char	*temp;
	int	fd;

	fd = open("text.txt", O_RDONLY);
	temp = get_next_line(fd);

	
		printf("%s", temp);

	return (0);
}