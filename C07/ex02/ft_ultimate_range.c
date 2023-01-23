/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 07:42:39 by bgauthie          #+#    #+#             */
/*   Updated: 2022/08/23 08:57:47 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size_of_range;
	int	n;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size_of_range = max - min;
	*range = malloc(sizeof(int) * size_of_range);
	if (*range == NULL)
		return (-1);
	n = 0;
	while (n < size_of_range)
	{
		range[0][n] = min;
		min++;
		n++;
	}
	return (size_of_range);
}
