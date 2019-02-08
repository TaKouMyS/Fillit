/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:39:34 by lgaultie          #+#    #+#             */
/*   Updated: 2019/01/31 21:05:54 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../libft/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_tetris
{
	t_point				a;
	t_point				b;
	t_point				c;
	t_point				d;
	t_point				pos;
	char				letter;
	int					height;
	int					width;
	struct s_tetris		*next;
	struct s_tetris		*prev;
}				t_tetris;

void			ft_free_list_from_begin(t_tetris *tetris);
void			ft_free_list_from_end(t_tetris *tetris);
char			*ft_read_file(const int fd);
t_tetris		*ft_check_and_letter(char *str, t_tetris *tetris);
t_tetris		*ft_check(char *str, t_tetris *tetris, int len, char ar[4][5]);
t_tetris		*ft_make_link(char tetri[4][5], t_tetris *tetris);
void			ft_lstendadd1(t_tetris **alst, t_tetris *new);
t_tetris		*ft_exit_check(char *save_str);
t_tetris		*ft_exit_check2(t_tetris *begin, char *save_str);
int				ft_create_map(size_t len, char **map);
void			ft_display_and_free_map(char **map, t_tetris *tetris);
int				ft_resize_map(char **map);
void			ft_clean_map(char **map);
int				ft_can_place(t_tetris *t, char **map, t_point coo);
t_point			ft_coo(int x, int y);
int				ft_move_tetri(t_tetris *t, char **map);
int				ft_solve(t_tetris *t, t_tetris *begin, char **map);
void			ft_free_map(char **map);
char			**ft_allocate_map(char **map);

#endif
