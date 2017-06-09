#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str);

char	*inverser(char* argv)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	j = ft_strlen(argv);

	tmp = (char*)malloc(sizeof(char) * j + 1);
	tmp[j] = '\0';
	j--;
	while (argv[i])
	{
		tmp[j] = argv[i];
		i++;
		j--;
	}
	return (tmp);
}

int	main(int argc, char **argv)
{
	argv[1] = inverser(argv[1]);
	printf("Valeur de l'entree : %s\n", argv[1]);
	return (0);
}