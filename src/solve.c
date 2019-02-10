/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:13:24 by lgaultie          #+#    #+#             */
/*   Updated: 2019/02/10 21:00:21 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		ft_move_tetri(t_tetris *t, char **map, int map_size)
{
	int	ret;

	map[(t->a.y) + (t->pos.y)][(t->a.x) + (t->pos.x)] = '.';
	map[(t->b.y) + (t->pos.y)][(t->b.x) + (t->pos.x)] = '.';
	map[(t->c.y) + (t->pos.y)][(t->c.x) + (t->pos.x)] = '.';
	map[(t->d.y) + (t->pos.y)][(t->d.x) + (t->pos.x)] = '.';
	ret = ft_chkplace(t, map, ft_coo((((t->pos.x) + 1)), t->pos.y), map_size);
	return (ret);
}

int		ft_chkplace(t_tetris *t, char **map, t_point coo, int map_size)
{
	while (1)
	{
		if (map[coo.y][coo.x] != '\0')
		{
			if (ft_verif_all_tetri(coo.x, coo.y, t, map) == 1)
			{
				ft_place_tetri(coo.x, coo.y, t, map);
				if (t->next == NULL)
					return (4);
				return (1);
			}
		}
		if (t->letter != 'A' && (map_size < (coo.y + t->height)))
			return (2);
		if (t->letter == 'A' && (map_size < (coo.y + t->height)))
			return (3);
		if (map[coo.y][coo.x + 1] == '\0'
			|| ((map_size < ((coo.x) + t->width))))
		{
			coo.x = -1;
			++coo.y;
		}
		++coo.x;
	}
}

int		ft_solve(t_tetris *t, t_tetris *begin, char **map)
{
	int	ret;
	int	map_size;

	map_size = ft_strlen(map[0]);
	ret = ft_chkplace(t, map, ft_coo(0, 0), map_size);
	while (ret != 4)
	{
		if (ret == 1 && (t = t->next))
			ret = ft_chkplace(t, map, ft_coo(0, 0), map_size);
		else if (ret == 2)
		{
			ret = ft_move_tetri(t->prev, map, map_size);
			t = t->prev;
		}
		else if (ret == 3)
		{
			ft_clean_map(map);
			map_size = ft_resize_map(map, map_size);
			ret = ft_chkplace(begin, map, ft_coo(0, 0), map_size);
			t = begin;
		}
	}
	return (0);
}
