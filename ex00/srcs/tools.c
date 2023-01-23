/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <marvin@42lyon.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:32:02 by lpupier           #+#    #+#             */
/*   Updated: 2022/08/21 20:39:04 by lpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] > s2[i])
				return (1);
			return (-1);
		}
		i ++;
	}
	if (s2[i] == '\0')
		return (0);
	else
		return (-1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_check_number(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13))
		idx++;
	while (str[idx] >= '0' && str[idx] <= '9')
		idx++;
	if (str[idx] == '\0')
		return (1);
	else
		return (0);
}
