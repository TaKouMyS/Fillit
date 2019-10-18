/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 20:53:30 by amamy             #+#    #+#             */
/*   Updated: 2019/10/18 21:47:59 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ft_read_file
** read 546 characters of file matching the file descriptor given and create
** a char *str allocated with just enough memory.
**
** Also, it checks on the 2 lasts chars (before \0), if they are none of '#'
** or '.' the programme will terminate.
*/

char	*ft_read_file(const int fd)
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
	len = ft_strlen(str);
	if (str[len - 2] != '.' && str[len - 2] != '#')
	{
		free(str);
		return (NULL);
	}
	return (str);
}

/*
** ft_sqrt_map
** Take a number and return the next perfect root square
*/

int		ft_sqrt_map(int nb)
{
	int	racine;

	racine = 1;
	if (nb < 0)
		return (0);
	while (racine * racine < nb)
		racine++;
	return (racine);
}

/*
** ft_coo :
** Used to input x and y in fct which takes t_point var
*/

t_point	ft_coo(int x, int y)
{
	t_point		coo;

	coo.x = x;
	coo.y = y;
	return (coo);
}
