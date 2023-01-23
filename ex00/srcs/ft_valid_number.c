/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <marvin@42lyon.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:07:40 by lpupier           #+#    #+#             */
/*   Updated: 2022/08/21 20:38:02 by lpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*add_zero(char *number, int nb_zero)
{
	int		i;
	int		len;
	int		size;
	char	*temp_number;

	len = ft_strlen(number);
	size = (len + nb_zero + 1);
	temp_number = malloc(sizeof(char) * size);
	i = 0;
	while (i < nb_zero)
	{
		temp_number[i] = '0';
		i++;
	}
	while (i < size)
	{
		temp_number[i] = number[i - nb_zero];
		i++;
	}
	temp_number[i] = '\0';
	return (temp_number);
}

char	*ft_valid_number(char *number)
{
	char	*true_number;
	int		idx;
	int		len;

	idx = 0;
	if (ft_strcmp(number, "") == 0)
	{
		ft_putstr("Error\n");
		return ("");
	}
	while (number[idx] == ' ' || number[idx] == '0')
		idx++;
	true_number = &number[idx];
	len = ft_strlen(true_number);
	if (len % 3 == 1)
		true_number = add_zero(true_number, 2);
	else if (len % 3 == 2)
		true_number = add_zero(true_number, 1);
	if (ft_strlen(true_number) == 0)
		true_number = "0";
	return (true_number);
}
