/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:34:24 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/27 17:13:52 by fgroenew         ###   ########.fr       */
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

#endif
