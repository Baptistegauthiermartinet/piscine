/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:24:30 by bgauthie          #+#    #+#             */
/*   Updated: 2022/08/07 16:51:37 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_int(int a, int b)
{
	int	c;

	c = a;
	a = b;
	b = c;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	n;
	int c;

	n = 0;
	while (n < size / 2)
	{
		c = tab[n];
		tab[n] = tab [size - 1- n];
		tab[size - 1 -n] = c;
		n++;
	}
}

#include <stdio.h>

int main()
{
	int tab[] = {9, 6, 4,8, -41536, 0, 0, 781895, -154, -1000};
	int count = 0;
	ft_rev_int_tab(tab, 10);
	while (count < 10)
	{
		printf("%d %s\n%c", tab[count], "erkguerjbdfkgh", 'j');
		count++;
	}
}

