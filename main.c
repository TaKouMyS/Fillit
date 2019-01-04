/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:10:12 by lgaultie          #+#    #+#             */
/*   Updated: 2019/01/04 13:52:25 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ft_readfile(const int fd);
char	**ft_stockarray(char *str);

int		main(int argc, char **argv)		//Appel les fonction si bon nombre d'arguments
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
		if (((str = ft_readfile(fd)) == NULL) || (ft_stockarray(str) == NULL))
		{
			ft_putstr("error");
			return (0);
		}
		//printf("checkfile renvoie : %d\n", ft_stock(str));

	}
	return (0);
}
