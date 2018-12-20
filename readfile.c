/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:02:07 by lgaultie          #+#    #+#             */
/*   Updated: 2018/12/20 19:37:35 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

int		ft_checkfile(char *str)
{
	int		count;
	int		i;

	i = 0;
	count = 1;
	while (str[i] != '\0')
	{
		if (i % 20 == 0 && i != 0)
		{
			if (str[i] != '\n')
				return (-1);
		}
		else
		{
			if (str[i] != '.' && str[i] != '#')
				return (-2);
		}
		printf("i = %d\n", i);
		i++;
	}
	return (0);
}

//lit tout le fichier et fous tout dans une str
//return NULL si le fichier dépasse max caracteres
//on appelle check_file qui verifie le fichier, si elle renvoie -1 -> error
char	*ft_readfile(const int fd)
{
	ssize_t		size;
	char		buff[547];
	char		*str;

	size = read(fd, buff, 546);
	if (size > 545)
		return (NULL);
	buff[size] = '\0';
	if (!(str = ft_strndup(buff, size + 1)))
		return (NULL);
	if (ft_checkfile(str) == -1)
		return (NULL);
	return (str);
}

#include <stdio.h>
int		main(int argc, char **argv)
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		ft_putstr("usage: fillit target_file");
		return (0);
	}
	if (argc == 2)
	{
		//if (check_size(fd) == -1)
		//	ft_putstr("error");
		// printf("str = %s\n", ft_readfile(fd));
		//if ((str = ft_readfile(fd)) == NULL)
		//	ft_putstr("error");
		str = ft_readfile(fd);
		//printf("str =%s\n", str);
		printf("checkfile renvoie : %d\n", ft_checkfile(str));
	}
	return (0);
}
