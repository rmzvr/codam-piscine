/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:50:22 by rmzvr             #+#    #+#             */
/*   Updated: 2024/07/19 17:51:14 by rzvir            ###   ########.fr       */
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

	if (is_possible_prime(nb))
	{
		i = 3;
		while (i <= ft_sqrt(nb))
		{
			if (nb % i == 0)
				return (0);
			i += 2;
		}
		return (1);
	}
	else
	{
		return (0);
	}
}

/* int	main(void)
{
	printf("%d", ft_is_prime(81));
	return (0);
} */