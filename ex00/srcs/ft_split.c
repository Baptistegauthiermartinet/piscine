/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <marvin@42lyon.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:50:19 by lpupier           #+#    #+#             */
/*   Updated: 2022/08/21 20:10:50 by lpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_nb_str(char *str, char *to_find)
{
	int	i;
	int	nb_str;
	int	count;

	nb_str = 0;
	if (!(*to_find))
		return (nb_str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = 0;
			while (to_find[i] == str[i] && to_find[i])
				i++;
			if (!to_find[i] && count != 0)
			{
				nb_str++;
				count = 0;
			}
		}
		else
			count++;
		str++;
	}
	return (nb_str);
}

int	ft_split_str(char *str, char *charset)
{
	int	i;
	int	idx;

	idx = 0;
	if (!(*charset))
		return (0);
	while (*str)
	{
		if (*str == *charset)
		{
			i = 0;
			while (charset[i] == str[i] && charset[i] && str[i])
				i++;
			if (!charset[i])
				return (idx);
		}
		str++;
		idx++;
	}
	return (idx);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i ++;
	}
	dest[n] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset, int *size_tab)
{
	char	**tab;
	int		nb_str;
	int		count;
	int		idx_min;
	int		idx_max;

	tab = NULL;
	nb_str = ft_nb_str(str, charset);
	tab = malloc(sizeof(char *) * nb_str + 1);
	count = 0;
	idx_min = 0;
	while (count <= nb_str)
	{
		idx_max = ft_split_str(&str[idx_min], charset);
		tab[count] = malloc(sizeof(char) * (idx_max + 1));
		tab[count] = ft_strncpy(tab[count], &str[idx_min], idx_max);
		idx_min += idx_max + ft_strlen(charset);
		count++;
	}
	tab[count] = 0;
	*size_tab = nb_str;
	return (tab);
}

char	**ft_split_line(char *line)
{
	char	**tab;
	int		idx_min;
	int		idx_max;
	int		idx;
	char	*line_split;

	idx_min = 0;
	idx_max = 0;
	idx = 0;
	tab = malloc(sizeof(char *) * 2);
	while (line[idx] >= '0' && line[idx] <= '9')
		idx++;
	idx_max = idx;
	line_split = malloc(sizeof(char) * (idx_max - idx_min) + 1);
	tab[0] = ft_strncpy(line_split, &line[idx_min], idx_max);
	while (line[idx] == ' ' || line[idx] == ':')
		idx++;
	idx_min = idx;
	while (line[idx])
		idx++;
	idx_max = idx;
	line_split = malloc(sizeof(char) * (idx_max - idx_min) + 1);
	tab[1] = ft_strncpy(line_split, &line[idx_min], idx_max);
	return (tab);
}
