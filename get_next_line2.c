#include "get_next_line.h"

int ft_parser(char** line, t_fd stock, int fd)
{
	char *bslashn;

	while (*stock.lines[fd] == '\n')
		stock.lines[fd]++;
	if ((bslashn = ft_strchr(stock.lines[fd], '\n')) != NULL)
	{
		bslashn[0] = '\0';
		stock.returned = (char*)malloc(sizeof(char) * ft_strlen(stock.lines[fd]) + 1);
		stock.returned[0] = '\0';
		stock.returned = ft_strjoin(stock.returned, stock.lines[fd]);
		stock.lines[fd] = bslashn + 1;
		*line = stock.returned;
		//printf("VALEUR DE LINE AVANT RENVOI : %s\n", *line);
		return (1);
	}
	else if (ft_strlen(stock.lines[fd]) > 0)
	{
		stock.returned = (char*)malloc(sizeof(char) * ft_strlen(stock.lines[fd]) + 1);
		stock.returned[ft_strlen(stock.lines[fd])] = '\0';
		stock.returned = ft_strjoin(stock.returned, stock.lines[fd]);
		*line = stock.returned;
		free(stock.lines[fd]);
		return (1);
	}
	return (0);
}

t_fd	ft_reader(int fd, t_fd stock)
{
	char	*buffer;

	buffer = NULL;
	//ft_bzero(buffer, BUFF_SIZE);
	buffer = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	ft_bzero(buffer, BUFF_SIZE);
		stock.lines[fd] = (char*)malloc(sizeof(char));
		if (stock.lines[fd])
			stock.lines[fd][0] = '\0';
		while ((stock.count = read(fd, buffer, BUFF_SIZE) > 0))
			stock.lines[fd] = ft_strjoin(stock.lines[fd], buffer);
		printf("VALEUR DE RENVOI DE LECTURE : %s\n", stock.lines[fd]);
		free(buffer);
	return (stock);
}

int	get_next_line(int fd, char **line)
{
	static t_fd stock;
//check si la lecture est plus faible que le buffer
	stock.i = 0;
	stock.count = 0;
	if (stock.lines == NULL)
	{
		stock.lines = (char**)malloc(sizeof(char*) * 256);
		if (stock.lines)
			while (stock.lines[stock.i])
				stock.lines[stock.i] = NULL;
	}
	if (stock.lines[fd] == NULL)
		stock = ft_reader(fd, stock);
	if (stock.count == -1)
		return (-1);
	return (ft_parser(line, stock, fd));
}