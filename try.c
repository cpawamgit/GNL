#include "get_next_line.h"

/*int cretetoto(toto)
{

}
*/
int main()
{
	int fd;

	fd = 1;
	static t_fd toto;
	if (toto.lines == NULL)
		toto.lines = (char**)malloc(sizeof(char*) * 256);
	if (toto.lines[fd] == NULL)
	{
		toto.lines[fd] = (char*)malloc(sizeof(char));
		toto.lines[fd][0] = '\0';
	}
	/*if (toto == NULL)
		toto = cretetoto(toto);*/
	return (0);
}