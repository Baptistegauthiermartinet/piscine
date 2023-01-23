/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <marvin@42lyon.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 09:06:18 by lpupier           #+#    #+#             */
/*   Updated: 2022/08/21 20:46:09 by lpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUF_SIZE 4096

typedef struct s_stock_dict
{
	char	*nb;
	char	*letters;
}	t_stock_dict;

// main.c
int					check_args(int argc, char **argv);

// tools.c
int					ft_strlen(char *str);
void				ft_putstr(char *str);
int					ft_strcmp(char *s1, char *s2);
int					ft_check_number(char *str);
char				*ft_strcpy(char *dest, char *src);

// dict_struct.c
int					ft_open_dict(char *path);
void				ft_read_dict(int file, char **dict_content);
char				*ft_str_to_letters(char *str);
struct s_stock_dict	*dict_struct(char *dict);

// display_number.c
void				display_number(char *number, t_stock_dict *tab_struct);

// ft_split.c
char				**ft_split(char *str, char *charset, int *size_tab);
char				**ft_split_line(char *line);

// ft_put_words.c
void				ft_put_words(char *nb, t_stock_dict *tab_struct);

// ft_valid_numbers.c
char				*ft_valid_number(char *number);

#endif
