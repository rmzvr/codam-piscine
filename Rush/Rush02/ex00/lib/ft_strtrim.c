/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:56:46 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/27 17:04:03 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_strtrim_front(char *str, char to_trim)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	j = 0;
	found = 0;
	while (str[i])
	{
		if (found || str[i] != to_trim)
		{
			str[j++] = str[i];
			found = 1;
		}
		i++;
	}
	str[j] = '\0';
}

void	ft_strtrim_back(char *str, char to_trim)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i] && str[i] == to_trim)
	{
		str[i] = '\0';
		i--;
	}
}
