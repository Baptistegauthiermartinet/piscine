/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <marvin@42lyon.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:25:42 by lpupier           #+#    #+#             */
/*   Updated: 2022/08/21 18:00:21 by lpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	display_number(char *number, t_stock_dict *tab_struct)
{
	int	idx;

	idx = 0;
	while (tab_struct[idx].letters != NULL)
	{	
		if (ft_strcmp(number, tab_struct[idx].nb) == 0)
		{
			ft_putstr(tab_struct[idx].letters);
			ft_putstr(" ");
			break ;
		}
		idx++;
	}
}
