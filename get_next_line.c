/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrmorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 10:58:32 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/02/24 10:58:34 by cyrmorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd	*ft_new_permabuffer(int fd, t_fd *prev, t_fd *next)
{
	t_fd *new;

	new = NULL;
	new = (t_fd *)malloc(sizeof(t_fd));
	new->eof = 0;
	new->fd = fd;
	new->line = (char *)malloc(sizeof(char));
	if (new->line)
		new->line[0] = '\0';
	new->prev = prev;
	new->next = next;
	new->swap = (char *)malloc(sizeof(char));
	if (new->swap)
		new->swap[0] = '\0';
	return (new);
}

t_fd	*ft_check_registered_fd(int fd, t_fd *permabuffer)
{
	if (permabuffer == NULL)
		permabuffer = ft_new_permabuffer(fd, NULL, NULL);
	if (fd > permabuffer->fd)
	{
		while (permabuffer->next != NULL && permabuffer->next->fd <= fd)
			permabuffer = permabuffer->next;
		if (permabuffer->fd != fd)
		{
			permabuffer->next = ft_new_permabuffer(fd, permabuffer,
				permabuffer->next);
			permabuffer = permabuffer->next;
		}
	}
	else if (fd < permabuffer->fd)
	{
		while (permabuffer->prev != NULL && permabuffer->prev->fd >= fd)
			permabuffer = permabuffer->prev;
		if (permabuffer->fd != fd)
		{
			permabuffer->prev = ft_new_permabuffer(fd, permabuffer->prev,
			permabuffer);
			permabuffer = permabuffer->prev;
		}
	}
	return (permabuffer);
}
/*
int		ft_reader(t_fd *permabuffer, char *buffer, char **line, int fd)
{
	char *bslashn;

	bslashn = NULL;
	while (bslashn == NULL || permabuffer->eof == 1)
	{
		if ((bslashn = ft_strchr(permabuffer->line, '\n')) != NULL)
		{
			bslashn[0] = '\0';
			bslashn++;
			while ((char)bslashn == '\n')
				bslashn++;
			permabuffer->swap = (ft_strjoin(permabuffer->swap, bslashn));
			*line = permabuffer->line;
			printf("Valeur de line avant renvoi : %s\n", *line);
			return (1);
		}
		if (permabuffer->eof == 1)
		{
			*line = permabuffer->line;
			printf("Valeur de line avant renvoi EOF : %s\n", *line);
			return (0);
		}
		if ((read(fd, buffer, BUFF_SIZE)) != 0)
		{
			permabuffer->line = ft_strjoin(permabuffer->line, buffer);
			printf("Valeur de BUFFER : %s\n", buffer);
		}
		else
			permabuffer->eof = 1;
	}
	return (0);
}
*/
int		ft_reader(t_fd *permabuffer, char *buffer, char **line, int fd)
{
	char	*bslashn;
	int	i;

	bslashn = NULL;
	i = 0;
	int reader = 0;
	while (read(fd, buffer, BUFF_SIZE) > 0)
	{
		permabuffer->line = ft_strjoin(permabuffer->line, buffer);
	}
	if (read(fd, buffer, BUFF_SIZE) == -1)
		return (-1);
	while (permabuffer->line && permabuffer->line[i] == '\n')
		i++;
	if ((bslashn = ft_strchr(&permabuffer->line[i], '\n')) != NULL)
	{
		bslashn[0] = '\0';
		permabuffer->swap = (ft_strjoin(permabuffer->swap, bslashn + 1));
		*line = &permabuffer->line[i];
		return (1);
	}
	else
	{
		*line = permabuffer->line;
		return (0);
	}
	*line = NULL;
	return (-1);
}

void	ft_del_if_needed(t_fd *permabuffer)
{
	
		ft_strdel(&permabuffer->line);
		permabuffer->line = (char *)malloc(sizeof(char));
		if (permabuffer->line)
			permabuffer->line[0] = '\0';
		permabuffer->line = ft_strjoin(permabuffer->line, permabuffer->swap);
		ft_strdel(&permabuffer->swap);
		permabuffer->swap = (char *)malloc(sizeof(char));
		if (permabuffer->swap)
			permabuffer->swap[0] = '\0';
	
}

int		get_next_line(const int fd, char **line)
{
	static t_fd *permabuffer = NULL;
	char		*buffer;

	buffer = NULL;
	buffer = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	ft_bzero(buffer, BUFF_SIZE);
	if (fd < 0)
		return (-1);
	permabuffer = ft_check_registered_fd(fd, permabuffer);
	ft_del_if_needed(permabuffer);
	return (ft_reader(permabuffer, buffer, line, fd));
}
