/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <marvin@42lyon.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:26:20 by lpupier           #+#    #+#             */
/*   Updated: 2022/08/21 20:33:56 by lpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_args(int argc, char **argv)
{
	int		idx_number;

	if (argc == 2)
		idx_number = 1;
	else if (argc == 3)
		idx_number = 2;
	else
		return (0);
	if (ft_check_number(argv[idx_number]) == 0)
		return (0);
	return (idx_number);
}

int	main(int argc, char **argv)
{
	int				idx_number;
	int				file;
	char			*dict_path;
	char			*dict_content;
	t_stock_dict	*tab_struct;

	dict_path = "numbers.dict";
	idx_number = check_args(argc, argv);
	if (idx_number != 0)
	{
		if (argc == 3)
			dict_path = argv[1];
		file = ft_open_dict(dict_path);
		if (file != -1)
		{
			ft_read_dict(file, &dict_content);
			tab_struct = dict_struct(dict_content);
			ft_put_words(ft_valid_number(argv[idx_number]), tab_struct);
		}
		else
			ft_putstr("Dict Error\n");
	}
	else
		ft_putstr("Error\n");
	return (0);
}
