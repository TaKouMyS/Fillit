/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:11:55 by lgaultie          #+#    #+#             */
/*   Updated: 2019/02/14 14:08:46 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ft_check line :
** Checks the first 4 chars of the given char * to verify they are '.' or '#'.
** if the 5th char isn't a '\n' the function return false as well.
*/

int				ft_check_line(char *str)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (str[i] != '.' && str[i] != '#')
			return (-1);
		i++;
	}
	if (str[4] != '\n')
		return (-1);
	return (0);
}

/*
** ft_check_tetri :
** Checks if a tetri contains the right number of '#' and that they are
** next to each other.
*/

int				ft_check_tetri(char tetri[4][5])
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

/*
** ft_check_line_store :
** Analyse the string to check and build the array matching a tetri
** This checks if we have '.', '#' ams '\n' at the right place
*/

int				ft_check_line_store(char *str, char tetri[4][5], int len)
{
	int		x;
	int		line;

	x = 0;
	line = -1;
	while (++line < 4)
	{
		if (ft_check_line(str) != 0)
			return (-1);
		while (x < 4)
		{
			tetri[line][x] = str[x];
			if (++x == 4)
				tetri[line][x] = '\0';
		}
		x = 0;
		str = str + 5;
	}
	len = ft_strlen(str);
	return (len);
}

/*
** ft_check :
** Checks tetri by tetri if the file is valid and make a linked list
** with a node for each tetri. Return a pointer to the begining of
** the list.
*/

t_tetris		*ft_check(char *str, t_tetris *tetris, int len, char ar[4][5])
{
	char		*save_str;
	t_tetris	*begin;

	save_str = str;
	while (len != 0)
	{
		if (((len = ft_check_line_store(str, ar, len)) == -1) \
			|| (str[20] != '\n' && len > 20) || (ft_check_tetri(ar) != 0))
			return (ft_exit_check2(begin, save_str));
		if (tetris == NULL)
		{
			if ((tetris = ft_make_link(ar, tetris)) == NULL)
				return (ft_exit_check(save_str));
			tetris->prev = NULL;
			begin = tetris;
		}
		else
			ft_lstendadd1(&tetris, ft_make_link(ar, tetris));
		if (str[0] != '\0')
			str = str + 21;
	}
	free(save_str);
	return (begin);
}

/*
** ft_check_and_letter :
** Give to check the str, the first node empty and the array
** Get from check the all list, we add a Letter for each tetri
*/

t_tetris		*ft_check_and_letter(char *str, t_tetris *tetris)
{
	char		ar[4][5];
	t_tetris	*begin;
	char		letter;
	int			len;

	len = 1;
	letter = 'A';
	if ((tetris = ft_check(str, tetris, len, ar)) == NULL)
		return (NULL);
	begin = tetris;
	while (tetris->next != NULL)
	{
		tetris->letter = letter;
		tetris = tetris->next;
		letter++;
	}
	tetris->letter = letter;
	return (begin);
}
