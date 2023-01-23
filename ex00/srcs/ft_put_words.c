/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <marvin@42lyon.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:00:07 by lpupier           #+#    #+#             */
/*   Updated: 2022/08/21 21:09:06 by lpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_decade(char c)
{
	char	*dec;

	dec = malloc(sizeof(char) * (2 + 1));
	if (!dec)
		return (0);
	dec[0] = c;
	dec[1] = '0';
	dec[2] = '\0';
	return (dec);
}

char	*ft_concat(char a, char b)
{
	char	*tenth;

	tenth = malloc(sizeof(char) * (2 + 1));
	if (!tenth)
		return (0);
	tenth[0] = a;
	tenth[1] = b;
	tenth[2] = '\0';
	return (tenth);
}

char	*ft_thousands(char c, int len)
{
	char	*thousand;
	int		i;

	thousand = malloc(sizeof(char) * (len + 1 + 1));
	if ((!thousand) || len == 0)
		return (0);
	thousand[0] = c;
	i = 1;
	while (i <= len)
	{
		thousand[i] = '0';
		i++;
	}
	thousand[i] = '\0';
	return (thousand);
}

void	ft_put_words(char *nb, t_stock_dict *tab_struct)
{
	int		len;
	int		i;
	char	*str_nb;
	char	*secur_thousand;

	if (ft_strcmp(nb, "") == 0)
		return ;
	str_nb = malloc(sizeof(char) * 2);
	str_nb[1] = '\0';
	len = ft_strlen(nb);
	i = 0;
	if (ft_strcmp(nb, "0") == 0)
	{
		display_number("0", tab_struct);
		return ;
	}
	while (nb[i])
	{
		if (nb[i] == '0' && nb[i + 1] == '0' && nb[i + 2] == '0' && i % 3 == 0)
		{
			len -= 3;
			i += 2;
		}
		else if (i % 3 == 0 && len % 3 == 0 && nb[i] != '0')
		{
			str_nb[0] = nb[i];
			display_number(str_nb, tab_struct);
			display_number("100", tab_struct);
		}
		else if (i % 3 == 1 && nb[i] != '0')
		{
			if (nb[i] == '1')
			{
				display_number(ft_concat(nb[i], nb[i + 1]), tab_struct);
				secur_thousand = ft_thousands('1', len - 3);
				if (secur_thousand != 0)
					display_number(secur_thousand, tab_struct);
				len -= 3;
				i++;
			}
			else
				display_number(ft_decade(nb[i]), tab_struct);
		}
		else if (i % 3 == 2)
		{
			if (nb[i] != '0')
			{
				str_nb[0] = nb[i];
				display_number(str_nb, tab_struct);
			}
			secur_thousand = ft_thousands('1', len - 3);
			if (secur_thousand != 0)
				display_number(secur_thousand, tab_struct);
			len -= 3;
		}
		i++;
	}
	ft_putstr("\n");
}
