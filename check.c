/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:15:50 by lgaultie          #+#    #+#             */
/*   Updated: 2019/01/04 14:22:21 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_verif(char **tab)	//verifie le nombre de liaisons, retourne -1 si fichier invalide
{
	int		i;
	int		x;
	int		y;
	int		liaisons;

	i = 0;
	x = 0;
	y = 0;
	liaisons = 0;
	while (tab[x] != '\0' && x < 4)
	{
		if (tab[x][y] == '#' && (tab[x][y + 1] == '#' && tab[x + 1][y] == '#'))
			liaisons = liaisons + 4;
		else if (tab[x][y] == '#' && (tab[x][y + 1] == '#' || tab[x + 1][y] == '#'))
			liaisons = liaisons + 2;
		//printf("liaisons = %d, tab[%d][%d] = %c\n",liaisons,x,y,tab[x][y]);
		y++;
		if (y == 5)
		{
			x++;
			y = 0;
		}
	}
	//printf("x = %d, y = %d\n",x,y);
	//printf("liaisons = %d, tab[%d][%d] = %c\n", liaisons, x, y, tab[x][y]);
	if (liaisons < 6 || liaisons > 8)
		return (-1);
	return (0);
}

int		ft_verifbloc(char **tab)		//verifie bon nombre de # et si les . et # et \n sont au bon endroit dans un bloc, renvoie -1 si pas bon
{
	int		x;
	int		y;
	int		compteur;

	x = 0;
	y = 0;
	compteur = 0;
	while (tab[x] != '\0' && x < 4)
	{
		if (tab[x][y] == '#')
			compteur++;
		if ((y >= 0 && y <= 3) && (tab[x][y] != '.' && tab[x][y] != '#'))
			return (-1);
		if (y == 4 && tab[x][y] != '\n')
			return (-1);
		y++;
		if (y == 5)
		{
			if (tab[x][y] == '#')
				compteur++;
			x++;
			y = 0;
		}
	//printf("compteur = %d, tab[%d][%d] = %c\n", compteur, x, y, tab[x][y]);
	}
	if (compteur != 4)
		return (-1);
	return (0);
}

char	**ft_stockarray(char *str)		//stock les 20 premiers caracteres de str dans un double tableau, retourne null si malloc fail
{
	char	**tab;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	tab = NULL;
	if (!(tab = malloc(sizeof(char*) * 5)))
		return (NULL);
	while (y < 5)
	{
		if (!(tab[y] = malloc(sizeof(char*) * 6)))
			return (NULL);
		y++;
	}
	y = 0;
	while (str[i] != '\0' && i < 20)
	{
		if (y == 5)
		{
			tab[x][y] = '\0';
			x++;
			y = 0;
		}
		tab[x][y] = str[i];
		i++;
		y++;
	}
	y = 0;
	x++;
	tab[x][y] = '\0';
	if (ft_verifbloc(tab) == -1)
		return (NULL);
	//ft_display_array2(tab);
	//printf("ma fonction verifbloc renvoie : %d\n", ft_verifbloc(tab));
	//printf("ma fonction verif renvoie : %d\n", ft_verif(tab));
	if (ft_verif(tab) == -1)
		return (NULL);
	return (tab);
}
