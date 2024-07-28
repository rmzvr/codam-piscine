/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:43:37 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 14:45:06 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "values.h"

void	ft_putstr(char *str, int with_newline)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	if (with_newline)
		write(1, "\n", 1);
}
