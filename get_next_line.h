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

# include <stdio.h> //to remove

#define BUFF_SIZE 32

typedef struct		s_fd
{
	int				fd;
	int				eof;
	char			*line;
	char			*swap;
	struct s_fd		*prev;
	struct s_fd		*next;
	struct s_fd		*swap;
	//possible d'ecrire un variable qui dirait que la lecture du FD est terminée
}					t_fd;

int	get_next_line(const int fd, char **line);

#endif
