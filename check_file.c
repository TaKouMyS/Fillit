/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:22:09 by lgaultie          #+#    #+#             */
/*   Updated: 2018/12/19 18:17:23 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

/*
on fait des read de buff a 5 et on analyse les buffs un a un 
..##\n
on fait un compteur i a chaque fois quil read = nombre de ligne
si i = 5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125 la ligne est: \n
si i%5 = 0 --> la ligne est \n
*/
int		check_file(const int fd)
{
	ssize_t		size;
	char		buff[6];
	int			count;
	int			j;

	count = 1;
	size = 1;
	while (size > 0)
	{
		j = 0;
		if (count % 5 == 0)
			size = read(fd, buff, 1);
		if (count % 5 != 0)
			size = read(fd, buff, 5);
		if (count % 5 == 0)
		{
			if (buff[0] != '\n' && buff[0] != '\0')
				return (-1);
		}
		if (count % 5 != 0)
		{
			if (buff[0] == '\0')
				return(-1);
			while (buff[j] != '\0' && j < 4)
			{
				if (buff[j] != '.' && buff[j] != '#')
					return (-1);
				j++;
			}
			if (buff[4] != '\n' && buff[4] != '\0')
				return (-1);
		}
		count++;
		ft_bzero(buff, 5);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		ft_putstr("usage: fillit target_file");
		return (0);
	}
	if (argc == 2)
	{
		// if (check_size(fd) == -1)	si jappelle check_size la tete de lecture de read est deja dans lespace
		// 	ft_putstr("error");
		//printf("check_size renvoie : %d\n", check_size(fd));
		printf("check_file renvoie : %d\n", check_file(fd));
		//du coup checkfile doit renvoyer une structure, car on pourra pas read a chaque new fichier
		
	}
	return (0);
}
