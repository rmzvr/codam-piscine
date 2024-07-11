/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:14:08 by rzvir             #+#    #+#             */
/*   Updated: 2024/07/11 17:26:21 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

/* int	main(void)
{
	int	a;
	int	b;

	a = 1;
	b = 2;
	printf("a = %d - b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("a = %d - b = %d\n", a, b);
	return (0);
} */
