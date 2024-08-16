/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:00:53 by rmzvr             #+#    #+#             */
/*   Updated: 2024/08/16 16:49:57 by rmzvr            ###   ########.fr       */
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

void	ft_rev_int_tab(int *tab, int size)
{
	while (size / 2)
	{
		ft_swap(tab, tab + --size);
		tab++;
		--size;
	}
}

/* int	main(void)
{
	int	ints[] = {1, 2, 3, 4, 5};
	ft_rev_int_tab(ints, 5);
	printf("%d", ints[0]);
	printf("%d", ints[1]);
	printf("%d", ints[2]);
	printf("%d", ints[3]);
	printf("%d", ints[4]);
	return (0);
} */
