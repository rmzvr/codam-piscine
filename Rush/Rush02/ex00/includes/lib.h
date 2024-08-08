/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:34:24 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 15:31:16 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

int		ft_strlen(char *str);
int		ft_is_numeric(char c);
void	ft_strtrim_front(char *str, char to_trim);
void	ft_strtrim_back(char *str, char to_trim);
int		ft_strcmp(char *s1, char *s2);
void	ft_strremove(char *str, int count);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
void	ft_putstr(char *str, int with_newline);
int		ft_show_error(void);
int		ft_str_is_numeric(char *str);
int		ft_is_only_zero(char *str);

#endif
