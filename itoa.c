/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:37:20 by bgauthie          #+#    #+#             */
/*   Updated: 2022/08/20 11:35:47 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count(int nb)
{
	int	count;

	count = 1;
	while (nb / 10 != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

void	ft_fill(int count, char *a, int nb)
{
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
		a[count] = nb % 10 + 48;
		nb /= 10;
		count--;
	}
}

char	*ft_itoa(int nb)
{
	char	*a;
	int		count;

	count = ft_count(nb);
	if (nb < 0)
		a = malloc(sizeof(char) * count + 2);
	else
		a = malloc(sizeof(char) * count + 1);
	if (a == NULL)
		return (NULL);
	if (nb == -2147483648)
		a = "-2147483648";
	ft_fill(count, a, nb);
	return (a);
}

#include <stdio.h>

int main()
{
	int n=-123456789;
	printf("%s", ft_itoa(n));
}
