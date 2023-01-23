/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:18:53 by bgauthie          #+#    #+#             */
/*   Updated: 2022/08/06 10:40:10 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int a, int b)
{
	char	t;
	char	u;

	t = a / 10 + 48;
	write(1, &t, 1);
	t = a % 10 + 48;
	write(1, &t, 1);
	write(1, " ", 1);
	u = b / 10 + 48;
	write(1, &u, 1);
	u = b % 10 + 48;
	write(1, &u, 1);
	if (a == 98 && b == 99)
	{
	}
	else
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_putchar(a, b);
			b++;
		}
		a++;
	}
}
