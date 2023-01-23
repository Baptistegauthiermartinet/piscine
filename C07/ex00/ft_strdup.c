/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:09:07 by bgauthie          #+#    #+#             */
/*   Updated: 2022/08/23 08:57:19 by bgauthie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	size = i;
	i = 0;
	dest = malloc(sizeof(char) * size + 1);
	if (dest == NULL)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
