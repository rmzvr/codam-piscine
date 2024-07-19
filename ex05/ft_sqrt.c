/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:50:22 by rmzvr             #+#    #+#             */
/*   Updated: 2024/07/18 17:26:15 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_has_perfect_square_root(int i)
{
	char	c;

	c = (i % 10) + '0';
	if (c == 49 || c == 52 || c == 53 || c == 54 || c == 57)
		return (1);
	return (0);
}

int	ft_sqrt(int nb)
{
	int	count;
	int	subtrahend;

	count = 0;
	subtrahend = 1;
	if (ft_has_perfect_square_root(nb))
	{
		while (nb > 0)
		{
			nb -= subtrahend;
			subtrahend += 2;
			count++;
		}
		if (nb == 0)
			return (count);
	}
	return (0);
}

int	main(void)
{
	printf("%d", ft_sqrt(621));
	return (0);
}
