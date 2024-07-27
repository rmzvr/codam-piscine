/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:25:42 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/27 14:53:46 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>

void	ft_strremove(char *str, int count)
{
	int	i = 0;
	int	strlen;

	strlen = ft_strlen(str);
	i = count;
	while (i <= strlen)
	{
		str[i - count] = str[i];
		i++;
	}
	str[i - count] = '\0';
}
