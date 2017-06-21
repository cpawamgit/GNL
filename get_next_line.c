/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrmorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 21:43:28 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/06/21 21:43:32 by cyrmorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin2(char *s1, char *s2, t_fd *s)
{
	s->i = 0;
	s->j = 0;
	s->concatstr = (char *)malloc(sizeof(char) * \
		(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s->concatstr)
		return (NULL);
	while (s1[s->i] != '\0')
	{
		s->concatstr[s->i] = s1[s->i];
		s->i++;
	}
	while (s2[s->j] != '\0')
	{
		s->concatstr[s->i] = s2[s->j];
		s->i++;
		s->j++;
	}
	s->concatstr[s->i] = '\0';
	ft_strdel(&s1);
	return (s->concatstr);
}

int			ft_parser(t_fd *s, int fd)
{
	s->buffer = ft_memalloc(BUFF_SIZE + 1);
	s->tmp = ft_strdup(s->stock[fd]);
	ft_strdel(&s->stock[fd]);
	while ((s->ret = read(fd, s->buffer, BUFF_SIZE)) >= -1 || 1)
	{
		if (s->ret == -1)
			return (-1);
		s->tmp = ft_strjoin2(s->tmp, s->buffer, s);
		if ((s->bslashn = ft_strchr(s->tmp, '\n')) != NULL)
		{
			s->bslashn[0] = '\0';
			s->stock[fd] = ft_strdup(s->bslashn + 1);
			s->retline = ft_strdup(s->tmp);
			return (1);
		}
		if (s->ret == 0 && ft_strlen(s->tmp) > 0)
		{
			s->retline = ft_strdup(s->tmp);
			return (2);
		}
		if (s->ret == 0 && ft_strlen(s->tmp) == 0)
			return (0);
		ft_bzero(s->buffer, BUFF_SIZE);
	}
	return (0);
}

int			ft_reader(t_fd *s, int fd, char **line)
{
	int ret;

	if ((ret = ft_parser(s, fd)) == 1)
	{
		*line = s->retline;
		return (1);
	}
	else if (ret == 0)
	{
		*line = NULL;
		ft_strdel(&s->retline);
		return (0);
	}
	else if (ret == -1)
	{
		*line = NULL;
		ft_strdel(&s->stock[fd]);
		return (-1);
	}
	else if (ret == 2)
	{
		*line = s->retline;
		return (1);
	}
	return (99);
}

int			get_next_line(int fd, char **line)
{
	static t_fd	s;
	int			ret;

	if (fd < 0 || !line || fd > 4999)
		return (-1);
	if (!s.stock[fd] || s.stock[fd] == NULL)
		s.stock[fd] = ft_memalloc(BUFF_SIZE + 1);
	ret = ft_reader(&s, fd, line);
	ft_strdel(&s.tmp);
	ft_strdel(&s.buffer);
	return (ret);
}
