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

# define BUFF_SIZE 32

typedef struct		s_fd
{
	char			*stock[5000];
	char			*bslashn;
	char			*tmp;
	char			*retline;
	char			*buffer;
	int				ret;
	int				i;
	int				j;
	char			*concatstr;
}					t_fd;

int					get_next_line(const int fd, char **line);

#endif
