/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_A.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:34:24 by amamy             #+#    #+#             */
/*   Updated: 2019/01/05 19:20:11 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ft_readfile(const int fd)
{
	ssize_t		size;
	char		buff[547];
	char		*str;

	size = read(fd, buff, 546);
	if (size > 545 || size < 20)
		return (NULL);
	if (size)
		buff[size] = '\0';
	if (!(str = ft_strndup(buff, size + 1)))
		return (NULL);
	return (str);
}

int		ft_check_line(char *str)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (str[i] != '.' && str[i] != '#')
		{
			return (-1);
		}
		i++;
	}
	if (str[4] != '\n' && ft_strlen(str) != 4)
	{
		return (-1);
	}
	return (0);
}

int		ft_check_tetri(char tetri[4][5])
{
	int	x;
	int	y;
	int	links;
	int	nb_sharp;

	x = -1;
	y = 0;
	nb_sharp = 0;
	links = 0;
	while ((y != 4 && x++ != 4))
	{
		if (tetri[y][x] == '#')
		{
			nb_sharp++;
			if (x < 3 && tetri[y][x + 1] == '#')
				links++;
			if (y < 3 && tetri[y + 1][x] == '#')
				links++;
		}
		if (x == 4 && y++ < 5)
			x = -1;
	}
	if (nb_sharp != 4 || (links != 3 && links != 4))
	{
		return (-1);
	}
	return (0);
}

int		ft_check_store(char *str)
{
	int		line;
	int		x;
	char	tetri[4][5];
	char	*save_str;
	int		len;

	save_str = str;
	line = 0;
	len = ft_strlen(str);
	if (str[len - 2] != '.' && str[len - 2] != '#')
		return (-1);
	while ((len = ft_strlen(str)) > 1)
	{
		while (line < 4)
		{
			//printf("str : |||%s|||\n", str);
			if (ft_check_line(str) != 0)
			{
		printf("str : |%s|\n", str);
				ft_putstr("laaa");
				return (-1);
			}
/////////// DEBUT ///////// copie une ligne du tetri dans le tableau
			x = 0;
			while (x < 4)
			{
				tetri[line][x] = str[x];
				x++;
				if (x == 4)
					tetri[line][x] = '\0';
			}
//////////////////// FIN /////////////
			line++;
			str = str + 5;
		}
		line = 0;
		if (str[0] != '\n' && ft_strlen(str) > 4)
		{
			ft_putstr("laaa");
			return (-1);
		}
		str++;
		if (ft_check_tetri(tetri) != 0)
		{	
			return (-1);
		}
	}
	return (0);
}

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
		if ((str = ft_readfile(fd)) == NULL)
		{
			ft_putstr("error");
			return (0);
		}
		if (ft_check_store(str) != 0)
		{
			ft_putstr("error");
			return (0);
		}
	}
	ft_putstr("VAAAALIIIIDDDDEEEE");
	return (0);
}

/*
**This is display only - TBR///////////////////
**	int y;
**	y = 0;
**	//while (tetri[y])
**	while (y < 4)
**	{
**		ft_putstr(tetri[y]);
**		ft_putchar('\n');
**		y++;
**	}
*/
