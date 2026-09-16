#include "libft.h"

int	ft_get_size(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		++i;
	return (i);
}

long	**ft_create_tab(char *fichier)
{
	char	**lines;
	char	**line;
	long	**tab;
	int	len;
	int	len_line;
	int	i;
	int	j;

	lines = ft_split(fichier, "\n");
	if (!lines)
		return (NULL);
	len = ft_get_size(lines);
	tab = malloc(sizeof(long *) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (lines[i])
	{
		line = ft_split(lines[i], ": ");
		if (!line)
			return (NULL);
		len_line = ft_get_size(line);
		tab[i] = malloc(sizeof(long) * (len_line + 1));
		j = 0;
		while (j < len_line)
		{
			tab[i][j] = ft_atoi(line[j]);
			free(line[j]);
			++j;
		}
		free(line);
		free(lines[i]);
		tab[i][j] = -1;
		++i;
	}
	free(lines);
	tab[i] = NULL;
	return (tab);
}

#include <stdio.h>

long	ft_day7(char *fichier)
{
	long	**tab;
	long	res;
	int	i;
	int	j;

	tab = ft_create_tab(fichier);
	if (!tab)
		return (-1);
	res = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] > 0)
		{
			printf("%ld|\n", tab[i][j]);
			++j;
		}
		free(tab[i]);
		++i;
	}
	free(tab);
	return (res);
}

int	main(int argc, char **argv)
{
	char	*fichier;

	if (argc != 2)
	{
		ft_putstr("Nombre d'arguments invalide.\n");
		return (1);
	}
	fichier = ft_get_fichier(argv[1]);
	ft_putnbr(ft_day7(fichier));
	free(fichier);
	return (0);
}
