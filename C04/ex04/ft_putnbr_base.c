/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:24:45 by bgauthie          #+#    #+#             */
/*   Updated: 2022/08/17 10:40:15 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_error(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (ft_strlen(str) <= 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		n = i + 1;
		while (str[n] != '\0')
		{
			if (str[i] == str [n])
				return (0);
			n++;
		}
		i++;
	}
	return (1);
}

void	ft_recur(unsigned int nbr, char *base, unsigned int size)
{
	if (nbr < size)
		ft_putchar(base[nbr]);
	else
	{
		ft_recur(nbr / size, base, size);
		ft_putchar(base[nbr % size]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	size = ft_strlen(base);
	if (ft_error(base) == 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_recur(-nbr, base, size);
	}
	else
		ft_recur(nbr, base, size);
}
