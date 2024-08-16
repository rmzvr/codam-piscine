/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:27:06 by rmzvr             #+#    #+#             */
/*   Updated: 2024/08/09 22:12:03 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_nbr(int n1, int n2, int n3)
{
	char	digit;

	digit = n1 + '0';
	write(1, &digit, 1);
	digit = n2 + '0';
	write(1, &digit, 1);
	digit = n3 + '0';
	write(1, &digit, 1);
}

void	ft_print_sep(int n1, int n2, int n3)
{
	if (n1 != 7 || n2 != 8 || n3 != 9)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				if (i != j && j != k && i != k)
				{
					ft_print_nbr(i, j, k);
					ft_print_sep(i, j, k);
				}
				k++;
			}
			j++;
		}
		i++;
	}
}

/* int	main(void)
{
	ft_print_comb();
	return (0);
} */
