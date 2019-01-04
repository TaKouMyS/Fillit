/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:13:59 by lgaultie          #+#    #+#             */
/*   Updated: 2019/01/04 14:15:14 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_readfile(const int fd)		//lis le fichier et stock dans str, retourne null si fichier invalide
{
	ssize_t		size;
	char		buff[547];
	char		*str;
	int			i;

	size = read(fd, buff, 546);
	if (size > 545 || size < 20)
		return (NULL);
	if (size)
	buff[size] = '\0';
	if (!(str = ft_strndup(buff, size + 1)))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (NULL);
		i++;
	}
	return (str);
}
