/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_valid_combinations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:37:07 by rzvir             #+#    #+#             */
/*   Updated: 2024/07/21 21:37:41 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_valid_combinations(char combinations[][5], int num_combinations)
{
	int		count;
	int		i;
	int		j;
	int		k;
	int		r;
	int		u;
	char	valid[4][4];

	count = 0;
	i = 0;
	while (i < num_combinations)
	{
		j = 0;
		while (j < count)
		{
			k = 0;
			while (k < 4)
			{
				if (combinations[i][k] == valid[j][k])
				{
					break ;
				}
				k++;
			}
			if (k == 4)
			{
				j++;
			}
			else
			{
				break ;
			}
		}
		if (j == count)
		{
			k = 0;
			while (k < 4)
			{
				valid[count][k] = combinations[i][k];
				k++;
			}
			count++;
		}
		i++;
	}
	r = 0;
	u = 0;
	while (r < 4)
	{
		u = 0;
		while (u < 4)
		{
			write(1, &valid[r][u], 1);
			if (u < 3)
			{
				write(1, " ", 1);
			}
			u++;
		}
		write(1, "\n", 1);
		r++;
	}
}