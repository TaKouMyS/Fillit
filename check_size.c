/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:55:26 by lgaultie          #+#    #+#             */
/*   Updated: 2018/12/19 15:43:16 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		check_size(const int fd)
{
	ssize_t		size;
	char		buff[546];

	size = read(fd, buff, 545);
	if (size > 544)
		return (-1);
	return (0);
}
