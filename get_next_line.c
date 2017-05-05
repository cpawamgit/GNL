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

/*static int ft_checker(char *buffer, int charread) //retourne l endroit ou le \n
{										// a ete trouve par un int ou retourne
	int i;								// 0 si aucun \n n'a ete trouve ou -1
										// si fin du fichier
	if (charread == 0)
		return (-1);
	i = 0;
	while (buffer)
	{
		if (buffer[i] == '\n')
			return(i);
		i++;
	}
	if (i == charread)
		return (0);
}*/

/*static int ft_reader(const int fd, int *fdtracker, char **line, char *tmp)
{
	int		charread;
	int		total;
	char	linereturn[2000];
	char	buffer[BUFF_SIZE];

	stopreading = 1;
	charread = 0;
	total = 0;
	while (charread = read(fd, buffer, BUFF_SIZE) >= 0 && 
		ft_checker(buffer, charread) > 0)
	{

	}
}*/
t_fd	*ft_new_permabuffer(int fd, t_fd *)
{
	t_fd *new;
	new = NULL;
	new = (t_fd *)malloc(sizeof(t_fd));
	
	new->eof = 0;
	new->fd = fd;
	new->line = (char *)malloc(sizeof(char));
	if (new->line)
		new->line[0] = '\0';
	new->prev = NULL;
	new->next = NULL;
	new->swap = NULL;
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
			permabuffer->next = ft_new_permabuffer(fd, permabuffer, permabuffer->next);
			permabuffer = permabuffer->next;
		}
	}
	else
		while (permabuffer->prev != NULL && fd < permabuffer->fd)
			permabuffer = permabuffer->prev;
		if (permabuffer->fd != fd)
		{
			permabuffer->prev = ft_new_permabuffer(fd, permabuffer->prev, permabuffer);
			permabuffer = permabuffer->prev;
		}
		return (permabuffer);
}


int	ft_check_bslashn_oef(int charsread, char *buffer, int *bslashn)
{
	int i;

	i = 0;
	if (BUFF_SIZE > charsread)
		return (1);
	while (i < charsread)
	{
		if (buffer[i] == '\n')
		{
			*bslashn = i;
			return (2);
		}
		i++;
	}
	return (0);
}

// ft_cut_and_stock cut the buffer from the first bslashn it founds, all 
// the first part being joined to the perma->line, and the rest going to perma->swap
char	*ft_cut_and_stock(t_fd *permabuffer, int bslashn, char *buffer)
{
	int i;
	int j;

	i = BUFF_SIZE - bslashn;
	j = 0;
	if (i > 0)
	{
		buffer[bslashn] = '\0';
		permabuffer->swap = (char *)malloc(sizeof(char) * i);
		if (permabuffer->swap)
		{
			i--;
			permabuffer->swap[i] = '\0';
			while (i > 0)
			{
				i--;
				j++;
				permabuffer->swap[i] = buffer[BUFF_SIZE - j];
			}
		}
	}
	permabuffer->line = ft_strjoin(permabuffer->line, buffer);
	return (permabuffer->line);
}

int	get_next_line(const int fd, char **line)
{
	//free le maillon avant de si perma->eof est a 1 lors du check
	static t_fd *permabuffer = NULL;	
	char buffer[BUFF_SIZE];
	int	charsread;
	int bslashn;

	if (fd < 0)
		return (-1);
	ft_bzero(buffer, BUFF_SIZE);
	if (permabuffer == NULL || fd != permabuffer->fd)
		permabuffer = ft_check_registered_fd(fd, permabuffer);


	

















	//il faut check le line de FD a free apres un eof
	if ((charsread = read(fd, buffer, BUFF_SIZE)) != 0)
	{
		//si lecture ok, on check si le maillon correspondant au FD existe
		if ((permabuffer = ft_check_registered_fd(fd, permabuffer)) == NULL)
		{// si non on le crée
			permabuffer = ft_new_permabuffer(fd);
			printf("check 1\n");
		}//si oui on l'ajoute et on check si \n ou eof apres
		if ((permabuffer = ft_check_registered_fd(fd, permabuffer)) != NULL)
		{
			printf("check 2\n");
			//I have to create a function that check if there is something in swap,
			//and in that case, transfer it to line, then free swap. And check if bslashn
			//are found in it.
			bslashn = 0;
			//que line soit NULL ou non on concatene
			while (bslashn == 0 && permabuffer->eof == 0)
			{
				printf("check 3\n");
				if (ft_check_bslashn_oef(charsread, buffer, &bslashn) == 1)
				{//cas de l'oef
			printf("check 4\n");
					permabuffer->line = ft_strjoin(permabuffer->line, buffer);
					permabuffer->eof = 1;
					*line = permabuffer->line;
				}
				else if (ft_check_bslashn_oef(charsread, buffer, &bslashn) == 2)
				{//cas du bslashn
					printf("check 5\n");
					*line = ft_cut_and_stock(permabuffer, bslashn, buffer);
					printf("check 6\n");
				}
				else
				{
					permabuffer->line = ft_strjoin(permabuffer->line, buffer);	
					charsread = read(fd, buffer, BUFF_SIZE);
				}
			}
		}
		printf("check 7\n");
	}
	*line = permabuffer->line;
	return (0);
}
