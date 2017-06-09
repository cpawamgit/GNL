/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrmorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 10:58:23 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/02/24 10:58:26 by cyrmorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

# define BUFF_SIZE 2

/*
typedef struct		s_fd
{
	int				fd;
	int				eof;
	char			*line;
	char			*swap;
	struct s_fd		*prev;
	struct s_fd		*next;
}					t_fd;
*/

typedef struct		s_fd
{	char			**lines;
	char			*returned;
	int				count;
	int 			i;
}					t_fd;

int					get_next_line(const int fd, char **line);

#endif
