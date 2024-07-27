/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:08:52 by rmzvr             #+#    #+#             */
/*   Updated: 2024/07/25 14:39:13 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*ints;
	int	i;

	size = max - min;
	ints = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		ints[i++] = min++;
	}
	return (ints);
}

/* int	main(void)
{
	int	*ints;
	int	i;
	int	min;
	int	max;
	int	size;

	min = -5;
	max = 5;
	ints = ft_range(min, max);
	size = max - min;
	i = 0;
	while (i < size)
	{
		printf("%d", ints[i]);
		i++;
	}
	free(ints);
	return (0);
} */
