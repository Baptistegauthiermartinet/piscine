/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 07:32:53 by bgauthie          #+#    #+#             */
/*   Updated: 2022/08/19 09:26:57 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*tab;
	unsigned int	size;
	unsigned int	n;

	if (min >= max)
	{
		tab = NULL;
		return (tab);
	}
	size = max - min;
	tab = malloc(sizeof(int) * size);
	if (tab == NULL)
		return (0);
	n = 0;
	while (n < size)
	{
		tab[n] = min;
		min++;
		n++;
	}
	return (tab);
}
