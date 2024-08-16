/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thousands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:32:51 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 12:47:12 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	create_thousands(char *str, int count)
{
	int	i;

	str[0] = '1';
	i = 1;
	while (i < count)
		str[i++] = '0';
	str[i] = '\0';
}