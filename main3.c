#include <stdlib.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int fd;
	int readc;
	char buffer[10];

	fd = open(av[1], O_RDONLY);
	while ((readc = read(fd, buffer, 10)) > 0)
	{
		printf("valeur de fd : %d", fd);
	}
	return (0);
}