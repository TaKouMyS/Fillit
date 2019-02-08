/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:13:24 by lgaultie          #+#    #+#             */
/*   Updated: 2019/02/02 23:05:45 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** ft_verif_all_tetri :
** Check if all the coordonates required to place the current tetris are
** available.
*/

int		ft_verif_all_tetri(int x, int y, t_tetris *tetris, char **map)
{
	if ((map[(tetris->a.y) + y][(tetris->a.x) + x] == '.') \
		&& (map[(tetris->b.y) + y][(tetris->b.x) + x] == '.') \
		&& (map[(tetris->c.y) + y][(tetris->c.x) + x] == '.') \
		&& (map[(tetris->d.y) + y][(tetris->d.x) + x] == '.'))
		return (1);
	return (0);
}

void	ft_place_tetri(int x, int y, t_tetris *tetris, char **map)
{
	tetris->pos.x = x;
	tetris->pos.y = y;
	map[(tetris->a.y) + y][(tetris->a.x) + x] = tetris->letter;
	map[(tetris->b.y) + y][(tetris->b.x) + x] = tetris->letter;
	map[(tetris->c.y) + y][(tetris->c.x) + x] = tetris->letter;
	map[(tetris->d.y) + y][(tetris->d.x) + x] = tetris->letter;
}

int		ft_move_tetri(t_tetris *t, char **map)
{
	int		ret;

	map[(t->a.y) + (t->pos.y)][(t->a.x) + (t->pos.x)] = '.';
	map[(t->b.y) + (t->pos.y)][(t->b.x) + (t->pos.x)] = '.';
	map[(t->c.y) + (t->pos.y)][(t->c.x) + (t->pos.x)] = '.';
	map[(t->d.y) + (t->pos.y)][(t->d.x) + (t->pos.x)] = '.';
	ret = ft_can_place(t, map, ft_coo((((t->pos.x) + 1)), t->pos.y));
	return (ret);
}

void	ft_display_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i][0] != '\0')
	{
		ft_putstr(map[i]);
		ft_putstr("\n");
	}
}

int		ft_can_place(t_tetris *t, char **map, t_point coo)
{
	int		map_size;

	map_size = 0;
	while (map[0][map_size] != '\0')
		map_size++;
			ft_putstr("Launching map:\n");
			ft_display_map(map);
			ft_putstr("end map:\n"); 
			ft_putstr("letter :");
			ft_putchar(t->letter);
			ft_putstr("\n");
	while (1)
	{
			ft_putstr("Map Size :");
			ft_putnbr(map_size);
			ft_putstr("\nWidth :");
			ft_putnbr(t->width);
			ft_putstr(" height :");
			ft_putnbr(t->height);
			ft_putstr("	x :");
			ft_putnbr(coo.x);
			ft_putstr(" Y :");
			ft_putnbr(coo.y);
			ft_putstr("\n");
		if (map[coo.y][coo.x] != '\0')
		{
			if (ft_verif_all_tetri(coo.x, coo.y, t, map) == 1)
			{
				ft_putstr("if 1\n");
				ft_place_tetri(coo.x, coo.y, t, map);
				if (t->next == NULL)
					return (4);
				return (1);
			}
		}
		// if (t->letter != 'A' && map[coo.y][(coo.x) + 1] == '\0' \
		// 	&& map[(coo.y) + 1][0] == '\0')
		if (t->letter != 'A' && (map_size < (coo.y + t->height)))
		{
			ft_putstr("if 2\n");
			return (2);
		}
		// if (t->letter == 'A' && map[coo.y][(coo.x) + 1] == '\0' \
		// 	&& map[(coo.y) + 1][0] == '\0')
		if (t->letter == 'A' && (map_size < (coo.y + t->height)))
		{
			ft_putstr("if 2\n");
			return (3);
		}
		if (map[coo.y][coo.x + 1] == '\0' || ((map_size < ( coo.x + t->width))))
		{
			coo.x = -1;
			coo.y++;
		}
		coo.x++;
	}
}

int		ft_solve(t_tetris *t, t_tetris *begin, char **map)
{
	int	ret;

	ret = ft_can_place(t, map, ft_coo(0, 0));
	while (ret != 4)
	{
		if (ret == 1)
		{
			ret = ft_can_place(t->next, map, ft_coo(0, 0));
			t = t->next;
		}
		if (ret == 2)
		{
			ret = ft_move_tetri(t->prev, map);
			t = t->prev;
		}
		if (ret == 3)
		{
			ft_clean_map(map);
			ft_resize_map(map);
			ret = ft_can_place(begin, map, ft_coo(0, 0));
			t = begin;
		}
	}
	return (0);
}
