/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:00:30 by bgauthie          #+#    #+#             */
/*   Updated: 2022/08/25 17:31:32 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_index(char c, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_count(int nb, int size)
{
	int	count;

	count = 1;
	while (nb / size != 0)
	{
		nb /= size;
		count++;
	}
	return (count);
}

void	ft_fill(char *a, long nb, int count, char *base)
{
	int	size;

	size = ft_strlen(base);
	if (nb < 0)
	{
		a[0] = '-';
		a[count + 1] = '\0';
		nb *= -1;
	}
	else
	{
		a[count] = '\0';
		count--;
	}
	while (count != -1 && nb != 0)
	{
		a[count] = base[nb % size];
		nb /= size;
		count--;
	}
}

char	*ft_itoa(int nb, char *base)
{
	char	*a;
	int		size;
	int		count;

	if (nb == 0)
	{
		a = malloc(sizeof(char) * 2);
		if (!a)
			return (NULL);
		a[0] = base[0];
		a[1] = '\0';
		return (a);
	}
	size = ft_strlen(base);
	count = ft_count(nb, size);
	if (nb < 0)
		a = malloc(sizeof(char) * count + 2);
	else
		a = malloc(sizeof(char) * count + 1);
	if (a == NULL)
		return (NULL);
	ft_fill(a, nb, count, base);
	return (a);
}
