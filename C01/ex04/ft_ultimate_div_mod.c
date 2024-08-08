/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:59:28 by rzvir             #+#    #+#             */
/*   Updated: 2024/07/11 18:07:09 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *a / *b;
	*b = temp % *b;
}

/* int	main(void)
{
	int	a;
	int	b;

	a = 6;
	b = 2;
	ft_ultimate_div_mod(&a, &b);
	printf("a = %d\nb = %d\n", a, b);
	return (0);
} */