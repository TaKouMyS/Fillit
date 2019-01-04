/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:39:34 by lgaultie          #+#    #+#             */
/*   Updated: 2019/01/04 11:46:18 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include "libft/libft.h"

typedef struct	s_tetris
{
	int					x1;		//abcisses
	int					y1;		//ordonnées
	int					x2;
	int					y2;
	int					x3;
	int					y3;
	int					x4;
	int					y4;
	char				*tetri;

	struct s_tetris		*next;

}				t_tetris;

#endif
