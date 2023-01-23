/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:32:59 by bgauthie          #+#    #+#             */
/*   Updated: 2022/08/17 13:30:56 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	x;

	i = 1;
	x = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (i != nb + 1)
	{
		x *= i;
		i++;
	}
	return (x);
}
