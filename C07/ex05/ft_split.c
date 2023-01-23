/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:32:07 by bgauthie          #+#    #+#             */
/*   Updated: 2022/08/25 14:35:09 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	if (charset[i] == '\0')
		return (0);
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_word_cpy(int *j, char *str, char *charset)
{
	int		str_idx;
	int		word_idx;
	char	*word;

	word_idx = 0;
	str_idx = *j;
	if (charset[0] == '\0')
		*j = ft_strlen(str);
	else
		while (ft_is_sep(str[*j], charset) == 0)
			(*j)++;
	word = malloc(sizeof(char) * (*j) + 1);
	if (!word)
		return (0);
	while (str_idx < *j)
	{
		word[word_idx] = str[str_idx];
		word_idx++;
		str_idx++;
	}
	word[word_idx] = '\0';
	return (word);
}

int	ft_word_nbr(char *str, char *charset)
{
	int	word_nbr;
	int	i;

	word_nbr = 0;
	i = 0;
	if (charset[i] == '\0')
		return (1);
	else
	{
		while (str[i])
		{
			while (ft_is_sep(str[i], charset) == 1)
			{
				i++;
				if (str[i] == '\0')
					return (word_nbr);
			}
			while (ft_is_sep(str[i], charset) == 0)
				i++;
			word_nbr += 1;
			i++;
		}
		return (word_nbr);
	}
}

char	**ft_split(char *str, char *charset)
{
	int		tab_idx;
	int		j;
	int		size;
	char	**tab;

	tab_idx = 0;
	j = 0;
	size = ft_word_nbr(str, charset);
	tab = malloc(sizeof(char *) * size + 1);
	if (!tab)
		return (0);
	while (tab_idx < size)
	{
		while (ft_is_sep(str[j], charset) == 1)
			j++;
		tab[tab_idx] = ft_word_cpy(&j, str, charset);
		tab_idx++;
	}
	tab [tab_idx] = 0;
	return (tab);
}
