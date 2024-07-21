/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_seen_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:36:13 by rzvir             #+#    #+#             */
/*   Updated: 2024/07/21 21:36:21 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max_seen_right(char *arr)
{
	int	max;
	int	i;
	int	count;

	max = 0;
	i = 3;
	count = 0;
	while (i >= 0)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			count++;
		}
		i--;
	}
	return (count);
}
