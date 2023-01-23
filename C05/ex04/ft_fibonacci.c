/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:38:54 by bgauthie          #+#    #+#             */
/*   Updated: 2022/08/15 14:09:41 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	x;

	x = 0;
	if (index < 0)
		return (-1);
	if (index == 1)
		return (1);
	if (index == 0)
		return (0);
	if (index >= 2)
		x = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (x);
}
