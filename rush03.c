/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizzo <mizzo@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:05:09 by rzvir             #+#    #+#             */
/*   Updated: 2024/07/16 12:45:15 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print(int count_x, int count_y, int x, int y)
{
	if (count_x == 0 && (count_y == 0 || count_y == y))
		ft_putchar('A');
	else if (count_x == x && (count_y == 0 || count_y == y))
		ft_putchar('C');
	else if (count_x == 0 || count_y == 0 || count_x == x || count_y == y)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

int	rush(int x, int y)
{
	int	count_x;
	int	count_y;

	if (x <= 0 || y <= 0)
	{
		write(1, "ERROR, x or y has to be a possitive number!\n", 45);
		return (1);
	}
	count_y = 0;
	while (count_y < y)
	{
		count_x = 0;
		while (count_x < x)
		{
			ft_print(count_x, count_y, x - 1, y - 1);
			count_x++;
		}
		ft_putchar('\n');
		count_y++;
	}
	return (0);
}
