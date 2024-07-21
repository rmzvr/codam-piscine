/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_combinations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:32:38 by rzvir             #+#    #+#             */
/*   Updated: 2024/07/21 22:01:25 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**generate_combinations(void)
{
	char	digits[4];
	char	**combination;
	int		i;
	int		j;
	int		k;
	int		l;
	int		s;

	digits[0] = '1';
	digits[1] = '2';
	digits[2] = '3';
	digits[3] = '4';
	i = 0;
	s = 0;
	combination = (char **)malloc(24 * sizeof(char *));
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (j != i)
			{
				k = 0;
				while (k < 4)
				{
					if (k != i && k != j)
					{
						l = 0;
						while (l < 4)
						{
							if (l != i && l != j && l != k)
							{
								combination[s] = (char *)malloc(5);
								combination[s][0] = digits[i];
								combination[s][1] = digits[j];
								combination[s][2] = digits[k];
								combination[s][3] = digits[l];
								combination[s][4] = '\0';
								s++;
							}
							l++;
						}
					}
					k++;
				}
			}
			j++;
		}
		i++;
	}
	return (combination);
}
