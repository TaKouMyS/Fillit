/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 10:35:37 by lgaultie          #+#    #+#             */
/*   Updated: 2019/01/31 19:46:09 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_free_list_from_begin(t_tetris *tetris)
{
	t_tetris	*tmp;

	while (tetris)
	{
		tmp = tetris;
		tetris = tetris->next;
		free(tmp);
	}
}

void		ft_free_list_from_end(t_tetris *tetris)
{
	t_tetris	*tmp;

	while (tetris)
	{
		tmp = tetris;
		tetris = tetris->prev;
		free(tmp);
	}
}

t_tetris	*ft_exit_check(char *save_str)
{
	free(save_str);
	return (NULL);
}

t_tetris	*ft_exit_check2(t_tetris *begin, char *save_str)
{
	if (begin != NULL)
		ft_free_list_from_begin(begin);
	free(save_str);
	return (NULL);
}

void		ft_free_map(char **map)
{
	int			i;

	i = 0;
	while (i < 20)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
