/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:27:06 by rmzvr             #+#    #+#             */
/*   Updated: 2024/08/16 11:47:50 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			if (i < 10)
				write(1, "0", 1);
			ft_putnbr(i);
			write(1, " ", 1);
			if (j < 10)
				write(1, "0", 1);
			ft_putnbr(j);
			if (i != 98 && i != 99)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}

/* int	main(void)
{
	ft_print_comb2();
	return (0);
} */
