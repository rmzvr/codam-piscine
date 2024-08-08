/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:08:52 by rmzvr             #+#    #+#             */
/*   Updated: 2024/07/27 12:51:54 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*ints;
	int	i;

	if (min >= max)
	{
		ints = NULL;
		return (ints);
	}
	size = max - min;
	ints = (int *)malloc(size * sizeof(int));
	if (ints == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ints[i++] = min++;
	}
	return (ints);
}

/* #include <stdio.h>

int	main(void)
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
