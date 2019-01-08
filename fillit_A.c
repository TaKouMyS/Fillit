/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_A.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamy <amamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:06:45 by amamy             #+#    #+#             */
/*   Updated: 2019/01/08 15:50:23 by amamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		if ((str = ft_readfile(fd)) == NULL)
		{
			ft_putstr("error");
			return (0);
		}
		if (ft_check(str) != 0)
		{
			ft_putstr("error");
			return (0);
		}
	}
	ft_putstr("VAAAALIIIIDDDDEEEE");
	return (0);
}