#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char buffer[50];
	int fd;
	fd = open(argv[1], O_RDONLY);
	read(fd, buffer, 50);
	printf("%d\n", ft_atoi(&buffer[8]));
	return (0);
}