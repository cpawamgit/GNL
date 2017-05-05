#include "get_next_line.h"

t_fd	*ft_new_permabuffer(int fd, int charsread)
{
	t_fd *new;
	new = NULL;
	new = (t_fd *)malloc(sizeof(t_fd));
	if (charsread != 0)
	{
		printf("control\n");
		new->eof = 0;
				printf("control2\n");
		new->fd = fd;
				printf("control3\n");
		new->line = NULL;
				printf("control4\n");
		new->next = NULL;
		new->swap = NULL;


	}
	else
		new->eof = 1;
	return (new);
}

int main()
{
	t_fd	*perma = NULL;
	perma = ft_new_permabuffer(0, 1);
	return (0);
}