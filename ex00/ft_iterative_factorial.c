/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:50:22 by rmzvr             #+#    #+#             */
/*   Updated: 2024/07/19 20:08:08 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb > 0)
	{
		while (nb > 0)
			res *= nb--;
	}
	else if (nb == 0)
	{
		res = 1;
	}
	else
		res = 0;
	return (res);
}

int	main(void)
{
	printf("%d", ft_iterative_factorial(0));
	return (0);
}