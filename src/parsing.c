/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:43:40 by lgaultie          #+#    #+#             */
/*   Updated: 2019/02/14 14:04:35 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ft_lstendadd :
** Add a node at the end of the list and initialize Next (null) and Previous.
*/

void			ft_lstendadd1(t_tetris **alst, t_tetris *new)
{
	t_tetris	*tmp;

	while ((*alst)->next != NULL)
		*alst = (*alst)->next;
	tmp = *alst;
	if (new)
		(*alst)->next = new;
	alst = &new;
	new->prev = tmp;
	alst = &tmp;
}

/*
** ft_optimize :
** Get the coordonate of the current t_tetris node and convert to be
** the closest to position 0:0, making it easier to put them on the map
*/

t_tetris		*ft_optimize(t_tetris *tetris)
{
	while (tetris->a.x != 0 && tetris->b.x != 0 && tetris->c.x != 0 \
		&& tetris->d.x != 0)
	{
		tetris->a.x = tetris->a.x - 1;
		tetris->b.x = tetris->b.x - 1;
		tetris->c.x = tetris->c.x - 1;
		tetris->d.x = tetris->d.x - 1;
	}
	while (tetris->a.y != 0 && tetris->b.y != 0 && tetris->c.y != 0 \
		&& tetris->d.y != 0)
	{
		tetris->a.y = tetris->a.y - 1;
		tetris->b.y = tetris->b.y - 1;
		tetris->c.y = tetris->c.y - 1;
		tetris->d.y = tetris->d.y - 1;
	}
	return (tetris);
}

/*
** ft_stock :
** fill the node given with the coordonate of the 4 blocks of a tetri
** and send it to optimize to calibrate coordonates with the point 0:0.
*/

t_tetris		*ft_stock(int x, int y, t_tetris *tetris, int nb_sharp)
{
	if (nb_sharp < 1 || nb_sharp > 4)
		return (NULL);
	if (nb_sharp == 1)
	{
		tetris->a.x = y;
		tetris->a.y = x;
	}
	if (nb_sharp == 2)
	{
		tetris->b.x = y;
		tetris->b.y = x;
	}
	if (nb_sharp == 3)
	{
		tetris->c.x = y;
		tetris->c.y = x;
	}
	if (nb_sharp == 4)
	{
		tetris->d.x = y;
		tetris->d.y = x;
	}
	tetris = ft_optimize(tetris);
	return (tetris);
}

/*
** ft_calculate_size :
** fill the node given with the height and width of the matching tetri
*/

t_tetris		*ft_calculate_size(t_tetris *tetris)
{
	int		ymax;
	int		xmax;

	ymax = 0;
	xmax = 0;
	if (tetris->a.x > xmax)
		xmax = tetris->a.x;
	if (tetris->b.x > xmax)
		xmax = tetris->b.x;
	if (tetris->c.x > xmax)
		xmax = tetris->c.x;
	if (tetris->d.x > xmax)
		xmax = tetris->d.x;
	if (tetris->a.y > ymax)
		ymax = tetris->a.y;
	if (tetris->b.y > ymax)
		ymax = tetris->b.y;
	if (tetris->c.y > ymax)
		ymax = tetris->c.y;
	if (tetris->d.y > ymax)
		ymax = tetris->d.y;
	tetris->height = ymax + 1;
	tetris->width = xmax + 1;
	return (tetris);
}

/*
** ft_make_link :
** create a t_tetri node and fill with '#' coordonates
** fill tetri->next and null
*/

t_tetris		*ft_make_link(char ar[4][5], t_tetris *tetris)
{
	int			x;
	int			y;
	int			nb_sharp;

	x = 0;
	y = 0;
	nb_sharp = 0;
	if (!(tetris = (t_tetris*)ft_memalloc(sizeof(t_tetris))))
		return (NULL);
	while (nb_sharp != 4)
	{
		if (ar[x][y] == '#')
			if ((tetris = ft_stock(x, y, tetris, ++nb_sharp)) == NULL)
				return (NULL);
		if (y == 3)
		{
			y = -1;
			x++;
		}
		y++;
	}
	tetris->next = NULL;
	tetris = ft_calculate_size(tetris);
	return (tetris);
}
