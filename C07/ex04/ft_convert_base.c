/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:00:07 by bgauthie          #+#    #+#             */
/*   Updated: 2022/08/25 13:57:35 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nb, char *base);
int		ft_error(char *str);
int		ft_atoi_base(char *str, char *base);
int		ft_strlen(char *str);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;

	if (ft_error(base_from) == 0 || ft_error(base_to) == 0)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	return (ft_itoa(nb, base_to));
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
		if (str[i] <= 32)
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

int	ft_check(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c != base[i])
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	signe;
	int	nb;
	int	size;

	i = 0;
	signe = 1;
	nb = 0;
	size = ft_strlen(base);
	if (ft_error(base) == 0)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (ft_check(str[i], base) == 1)
	{
		nb = nb * size + ft_index(str[i], base);
		i++;
	}
	return (nb * signe);
}
