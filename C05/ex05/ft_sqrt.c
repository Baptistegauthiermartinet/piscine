/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:10:11 by bgauthie          #+#    #+#             */
/*   Updated: 2022/08/17 19:28:45 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb == 1)
		return (1);
	if (nb < 2)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0 && i == nb / i)
			return (i);
		i++;
	}
	return (0);
}
