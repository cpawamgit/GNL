#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	printf("fd : %d\n", fd);
	get_next_line(fd, &line);
	ft_putstr("line returned :");
	ft_putstr(line);
	write(1, "\n", 1);
	get_next_line(fd, &line);
	ft_putstr("line returned :");
	ft_putstr(line);
	write(1, "\n", 1);
	get_next_line(fd, &line);
	ft_putstr("line returned :");
	ft_putstr(line);
	write(1, "\n", 1);
	return (0);
}