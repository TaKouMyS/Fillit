/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:34:24 by amamy             #+#    #+#             */
/*   Updated: 2019/01/03 18:35:09 by amamy            ###   ########.fr       */
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

int	ft_check_line(char *str)
{
	int	i;

	i = 0;
	while (i < 4)
	{
	//	printf("str[%d] :%c\n", i, str[i]);
		if (str[i] != '.' && str[i] != '#')
		{
			return (-1);
		}
		i++;
	}
	if (str[4] != '\n')
	{
		return (-1);
	}
	return(0);
}

int	ft_check_store(char *str)
{
	int		line;
	int		x;
	char	tetri[4][6];
	char	*save_str;

	save_str = str;
	line = 0;
	//while (ft_strlen(str) > 19) la vrai condition mais pour l'instant ca boucle
	//while (line <4)
//	{
		while (line < 4)
		{
			if (ft_check_line(str) != 0)
			{
				return (-1);
			}
		//ft_strncpy(tetri[line], str, 5); v1 : mais pb, on teste en codant un truc sur mesure :
		x = 0;
		while (x < 5)
		{
			tetri[line][x] = str[x];
			x++;
			if (x == 5)
			{
				tetri[line][x] = '\0';
			}
		}
	printf("tetri[%d]:%s:\n", line, tetri[line]);
		line++;
		str = str + 5;
		}
	//}
///////////////////////////////
/*
	int x;
	int y;

	x = 0;
	y = 0;
	//while (tetri[y])
	while (y < 4)
	{
		ft_putstr(tetri[y]);
		ft_putchar('\n');
		y++;
	}
*///////////////////////////////
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
	return (0);
}