/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:12:45 by amamy             #+#    #+#             */
/*   Updated: 2019/10/18 21:44:43 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ft_allocate_map :
** Just allocate the map for 20 char * using memalloc
** to put '\0' all arround the map.
*/

char		**ft_allocate_map(char **map)
{
	int i;

	i = 0;
	if (!(map = ft_memalloc(sizeof(char *) * 20)))
		return (NULL);
	while (i < 20)
	{
		if (!(map[i] = ft_memalloc(sizeof(char) * 20)))
			return (NULL);
		i++;
	}
	return (map);
}

void		ft_display_and_free_map(char **map, t_tetris *tetris, int fd)
{
	int	i;

	i = -1;
	while (map[++i][0] != '\0')
	{
		ft_putstr(map[i]);
		ft_putstr("\n");
	}
	ft_free_map(map);
	ft_free_list_from_begin(tetris);
	close(fd);
}

/*
** ft_resize_map
** add ann extra column and an extra line to the map
*/

int			ft_resize_map(char **map, int map_size)
{
	int		x;
	int		save_x;
	int		y;

	x = 0;
	save_x = 0;
	y = 0;
	while (map[y][x] != '\0')
		x++;
	save_x = x;
	if (save_x > 20)
		return (1);
	while (y < save_x)
	{
		map[y][x] = '.';
		y++;
	}
	x = 0;
	while (map[y][x] == '\0' && x < save_x + 1)
	{
		map[y][x] = '.';
		x++;
	}
	return (map_size + 1);
}

/*
** ft_create_map :
** Take a 20 * 20 map filled with '\0' and draw a map the size that
** allows to build the perfect square with this tetris's number.
*/

int			ft_create_map(size_t len, char **map)
{
	int		x;
	int		y;
	int		square_size;

	y = 0;
	x = 0;
	square_size = (ft_sqrt_map((len / 20.5) * 4));
	while (y < (square_size))
	{
		map[y][x++] = '.';
		if (x == square_size)
		{
			y++;
			x = 0;
		}
	}
	return (0);
}

/*
** ft_clean_map
** Remove all letters from the map and replace them with points
*/

void		ft_clean_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y][0] != '\0')
	{
		if (map[y][x] != '.' && map[y][x] != '\0')
			map[y][x] = '.';
		x++;
		if (map[y][x] == '\0')
		{
			y++;
			x = 0;
		}
	}
}
