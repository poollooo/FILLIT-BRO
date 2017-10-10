#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "libft.h"

int		test_strsplit( void )
{
	char	*c1;
	char	**c_tab;
	char	**s_tab;
	int		r00 = 0;

	c1 = strdup("Bonjour***les****haricots !");
	c_tab = (char **)malloc(sizeof(char *) * 3);
	c_tab[0] = strdup("Bonjour");
	c_tab[1] = strdup("les");
	c_tab[2] = strdup("haricots !");

	s_tab = ft_strsplit(c1, '*');
	int		i = 0;
	while (i < 3)
	{
		if (strcmp(s_tab[i], c_tab[i]) != 0)
			r00 = 1;
		i++;
	}

	free(c1);
	free(c_tab[0]);
	free(c_tab[1]);
	free(c_tab[2]);
	if (r00 == 0) {
		printf( "ft_strsplit: [ok]\n" );
		return 1;
	}
	printf( "ft_strsplit: [fail]\n" );
	return 0;
}

int main(void)
{
	test_strsplit();
}
