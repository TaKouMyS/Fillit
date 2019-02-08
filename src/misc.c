/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 20:53:30 by amamy             #+#    #+#             */
/*   Updated: 2019/02/01 11:50:53 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ft_read_file
** read 546 characters of file matching the file descriptor given and create
** a char *str allocated with just enough memory.
**
** Also, it checks ont the 2 lasts chars (before \0), if they are none of '#'
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
** ft_allocate_map : 
** Just allocate the map for 20 char * using memalloc
** to put '\0' all arround the map.
*/
char	**ft_allocate_map(char **map)
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

/*
** ft_coo :
** Used to inut x and Y in fct which takes t_point var
*/

t_point	ft_coo(int x, int y)
{
	t_point	coo;

	coo.x = x;
	coo.y = y;
	return (coo);
}
