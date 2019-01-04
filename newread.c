/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 17:51:21 by lgaultie          #+#    #+#             */
/*   Updated: 2019/01/03 18:25:54 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_display_array2(char **tab)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = 4;
	while (i < size)
	{
		while (tab[i][j] != '\0')
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

int		ft_verif(char **tab)
{
	int		i;
	int		x;
	int		y;
	int		liaisons;

	i = 0;
	x = 0;
	y = 0;
	liaisons = 0;
	while (tab[x] != '\0')
	{
		if (tab[x][y] == '#' && (tab[x][y + 1] == '#' || tab[x + 1][y] == '#'))
			liaisons = liaisons + 2;
		if (y == 5)
		{
			x++;
			y = 0;
		}
		y++;
	}
	printf("x = %d, y = %d\n",x,y);
	printf("liaisons = %d, tab[%d][%d] = %d\n", liaisons, x, y, tab[x][y]);
	if (liaisons < 6 || liaisons > 8)
		return (-1);
	return (0);
}

 char	**ft_stockarray(char *str)
{
	char	**tab;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	tab = NULL;
	if (!(tab = malloc(sizeof(char*) * 5)))
		return (NULL);
	while (y < 5)
	{
		if (!(tab[y] = malloc(sizeof(char*) * 6)))
			return (NULL);
		y++;
	}
	y = 0;
	while (str[i] != '\0' && i < 20)
	{
		if (y == 5)
		{
			tab[x][y] = '\0';
			x++;
			y = 0;
		}
		tab[x][y] = str[i];
		i++;
		y++;
	}
	y = 0;
	x++;
	tab[x][y] = '\0';
	ft_display_array2(tab);
	printf("ma fonction verif renvoie : %d\n", ft_verif(tab));
	//if (ft_verif(tab) == -1)
	//	return (NULL);
	// if (ft_verif(tab) == -1)
	// 	return (NULL);
	return (tab);
}

char	*ft_readfile(const int fd)
{
	ssize_t		size;
	char		buff[547];
	char		*str;
	int			i;

	size = read(fd, buff, 546);
	if (size > 545 || size < 20)
		return (NULL);
	//ft_putnbr(size);
	if (size)
	buff[size] = '\0';
	if (!(str = ft_strndup(buff, size + 1)))
		return (NULL);
	//if (ft_stock(str) == -1)
	//	return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (NULL);
		i++;
	}
	return (str);
}

#include <stdio.h>
int		main(int argc, char **argv)
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		ft_putstr("usage: fillit target_file");
		return (0);
	}
	if (argc == 2)
	{
		if (((str = ft_readfile(fd)) == NULL) || (ft_stockarray(str) == NULL))
		{
			ft_putstr("error");
			return (0);
		}
		//printf("checkfile renvoie : %d\n", ft_stock(str));

	}
	return (0);
}
