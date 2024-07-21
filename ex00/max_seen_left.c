/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_seen_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:35:01 by rzvir             #+#    #+#             */
/*   Updated: 2024/07/21 21:35:20 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max_seen_left(char *arr)
{
	int	max;
	int	i;
	int	count;

	max = 0;
	i = 0;
	count = 0;
	while (i < 4)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			count++;
		}
		i++;
	}
	return (count);
}