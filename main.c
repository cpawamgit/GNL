#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int 	fd2;
	int		fd3;
	char	*line;

	int i = 0;

	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open(argv[3], O_RDONLY);
	//printf("fd : %d\n", fd);
	//printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n\n");
	//printf("Premier Appel\n");
	//printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	while (i < 4)
	{
	printf("*** Valeur de retour de GNL FD 1 :%d\n", get_next_line(fd, &line));
	ft_putstr("line returned :");
	ft_putstr(line);
	write(1, "\n", 1);
	i++;
	}
	i = 0;
	while (i < 4)
	{
	printf("*** Valeur de retour de GNL FD 2 : %d\n", get_next_line(fd2, &line));
	ft_putstr("line returned :");
	ft_putstr(line);
	write(1, "\n", 1);
	i++;
	}
	i = 0;
	while (i < 4)
	{
	printf("*** Valeur de retour de GNL FD 3 : %d\n", get_next_line(fd3, &line));
	ft_putstr("line returned :");
	ft_putstr(line);
	write(1, "\n", 1);
	i++;
	}
	i = 0;
	while (i < 4)
	{
	printf("*** Valeur de retour de GNL FD 1 : %d\n", get_next_line(fd, &line));
	ft_putstr("line returned :");
	ft_putstr(line);
	write(1, "\n", 1);
	i++;
	}
	i = 0;
	while (i < 4)
	{
	printf("*** Valeur de retour de GNL : FD 2 %d\n", get_next_line(fd2, &line));
	ft_putstr("line returned :");
	ft_putstr(line);
	write(1, "\n", 1);
	i++;
	}
	i = 0;
	while (i < 4)
	{
	printf("*** Valeur de retour de GNL FD 3 : %d\n", get_next_line(fd3, &line));
	ft_putstr("line returned :");
	ft_putstr(line);
	write(1, "\n", 1);
	i++;
	}
	i = 0;
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