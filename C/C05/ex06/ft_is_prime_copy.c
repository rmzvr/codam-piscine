/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime_copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:50:22 by rmzvr             #+#    #+#             */
/*   Updated: 2024/10/01 18:08:59 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	count;
	int	subtrahend;

	count = 0;
	subtrahend = 1;
	while (nb >= subtrahend)
	{
		nb -= subtrahend;
		subtrahend += 2;
		count++;
	}
	return (count);
}

int	is_possible_prime(int nb)
{
	char	c;

	c = (nb % 10) + '0';
	if (nb == 2 || nb == 5)
		return (1);
	else if (nb <= 1 || nb % 2 == 0 || c == 53)
		return (0);
	return (1);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	nb_sqrt;
	int	c;

	c = 0;
	nb_sqrt = ft_sqrt(nb);
	if (is_possible_prime(nb))
	{
		i = 5;
		while (i * i <= nb)
		{
			c++;
			if (nb % i == 0)
				return (0);
			i += 6;
		}
		printf("c = %d", c);
		return (1);
	}
	else
	{
		return (0);
	}
}

int	main(void)
{
	printf("%d", ft_is_prime(1634300119));
	return (0);
}