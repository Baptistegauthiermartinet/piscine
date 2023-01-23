/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:07:26 by bgauthie          #+#    #+#             */
/*   Updated: 2022/08/25 10:52:53 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_count(char **strs, int size, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		count += ft_strlen(strs[i]);
		i++;
	}
	count += (size - 1) * ft_strlen(sep);
	return (count);
}

char	*ft_concat(char *dest, char *src)
{
	int	i;
	int	j;

	if (src[0] == '\0')
		return (dest);
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		row_index;
	int		len;
	char	*out;

	if (size == 0)
	{
		out = malloc(sizeof(char) * 1);
		out[0] = '\0';
		return (out);
	}
	len = ft_count(strs, size, sep);
	out = malloc(sizeof(char) * len + 1);
	if (out == NULL)
		return (0);
	*out = 0;
	row_index = 0;
	while (row_index < size)
	{
		ft_concat(out, strs[row_index]);
		if (row_index < size - 1)
			ft_concat(out, sep);
		row_index++;
	}
	out[len] = '\0';
	return (out);
}
