#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	int i = 0;

	fd = open(argv[1], O_RDONLY);
	//printf("fd : %d\n", fd);
	//printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n\n");
	//printf("Premier Appel\n");
	//printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	while (i < 11)
	{
	get_next_line(fd, &line);
	ft_putstr("line returned :");
	ft_putstr(line);
	write(1, "\n", 1);
	i++;
	}
	//printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n\n");
	//printf("Deuxieme Appel\n");
	//printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	//get_next_line(fd, &line);
	//ft_putstr("line returned :");
	//printf("%s\n", line);
	//write(1, "\n", 1);
	//printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n\n");
	//printf("Troisieme Appel\n");
	//printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	//get_next_line(fd, &line);
	//ft_putstr("line returned :");
	//ft_putstr(line);
	//write(1, "\n", 1);
	return (0);
	

	/*
	get_next_line(3, &line);
	get_next_line(5, &line);
	get_next_line(4, &line);
	get_next_line(6, &line);
	get_next_line(7, &line);
	get_next_line(6, &line);
	get_next_line(12, &line);
	get_next_line(13, &line);
	get_next_line(11, &line);
	get_next_line(12, &line);
	*/

}


//si dans le swap y a un bslashn, cut le swap dans line