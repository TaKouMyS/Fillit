/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_A.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:09:22 by amamy             #+#    #+#             */
/*   Updated: 2019/01/08 17:24:37 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_display(char tetri[4][5])
{
	int y;

	y = 0;
	while (y < 4)
	{
		ft_putstr(tetri[y]);
		ft_putchar('\n');
		y++;
	}
}

char	*ft_readfile(const int fd)
{
	ssize_t		size;
	char		buff[547];
	char		*str;
	int			len;

	size = read(fd, buff, 546);
	if (size > 545 || size < 20)
		return (NULL);
	if (size)
		buff[size] = '\0';
	if (!(str = ft_strndup(buff, size + 1)))
		return (NULL);
	return (str);
	len = ft_strlen(str);
	if (str[len - 2] != '.' && str[len - 2] != '#')
		return (NULL);
}

int		ft_check_line(char *str)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (str[i] != '.' && str[i] != '#')
			return (-1);
		i++;
	}
	if (str[4] != '\n' && ft_strlen(str) != 4)
		return (-1);
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
		return (-1);
	return (0);
}

int		ft_check_line_store(char *str, char tetri[4][5], int line)
{
	int		x;

	if (ft_check_line(str) != 0)
		return (-1);
	x = 0;
	while (x < 4)
	{
		tetri[line][x] = str[x];
		if (++x == 4)
			tetri[line][x] = '\0';
	}
	return (0);
}

int		ft_check(char *str)
{
	int		line;
	char	tetri[4][5];
	char	*save_str;
	int		len;

	save_str = str;
	while ((len = ft_strlen(str)) != 0)
	{
		if (str[len] == '\0')
			line = -1;
		while (++line < 4)
		{
			if (ft_check_line_store(str, tetri, line) != 0)
			{
				free(save_str);
				return (-1);
			}
			str = str + 5;
		}
		if ((str[0] != '\n' && ft_strlen(str) > 4) || (ft_check_tetri(tetri) != 0))
		{
			free(save_str);
			return (-1);
		}
		if (str[0] != '\0')
			str++;
	}
	return (0);
}
