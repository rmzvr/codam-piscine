/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:05:09 by rzvir             #+#    #+#             */
/*   Updated: 2024/07/13 13:37:04 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	rush(int x, int y)
{
	int	count_x;
	int	count_y;

	count_y = 0;
	while (count_y < y)
	{
		count_x = 0;
		while (count_x < x)
		{
			ft_print(count_x, count_y, x - 1, y - 1);
			count_x++;
		}
		count_y++;
	}
}
