/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <marvin@42lyon.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:39:10 by lpupier           #+#    #+#             */
/*   Updated: 2022/08/21 20:40:23 by lpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_open_dict(char *path)
{
	int	file;

	file = open(path, O_RDONLY);
	return (file);
}

void	ft_read_dict(int file, char **dict_content)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	ret = read(file, buf, BUF_SIZE);
	buf[ret] = '\0';
	*dict_content = buf;
}

char	*ft_str_to_letters(char *str)
{
	char	*word;
	int		idx;
	int		size_word;
	int		start_word;

	idx = 0;
	size_word = 0;
	while (str[idx] == ' ')
		idx++;
	start_word = idx;
	while (str[idx])
	{
		idx++;
		size_word++;
	}
	word = ft_strcpy(malloc(sizeof(char) * size_word + 1), &str[start_word]);
	return (word);
}

struct s_stock_dict	*dict_struct(char *dict)
{
	t_stock_dict	*tab_struct;
	char			**tab_line;
	char			**tab_split_line;
	int				count;
	int				size_dict;

	size_dict = 0;
	tab_line = ft_split(dict, "\n", &size_dict);
	tab_struct = malloc(sizeof(t_stock_dict) * (size_dict + 1));
	if (!(tab_struct))
		return (NULL);
	count = 0;
	while (tab_line[count])
	{
		tab_split_line = ft_split_line(tab_line[count]);
		tab_struct[count].nb = tab_split_line[0];
		tab_struct[count].letters = ft_str_to_letters(tab_split_line[1]);
		count++;
	}
	tab_struct[count].nb = 0;
	tab_struct[count].letters = 0;
	return (tab_struct);
}
