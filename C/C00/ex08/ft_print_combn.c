/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:55:34 by rmzvr             #+#    #+#             */
/*   Updated: 2024/09/24 14:18:11 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str, int with_separator)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	if (with_separator)
		write(1, ", ", 2);
}

void	ft_init_comb(char *comb, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		comb[i] = i + '0';
		i++;
	}
	comb[i] = '\0';
}

int	ft_is_comb_done(char *comb, int n)
{
	int	i;

	i = 0;
	if (comb[n - 1] != '9')
		return (0);
	while (comb[i + 1] != '\0')
	{
		if (comb[i] + 1 != comb[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_fill_comb(char *comb, int n)
{
	int	i;

	i = n - 1;
	while (!ft_is_comb_done(comb, n))
	{
		ft_putstr(comb, 1);
		if (comb[i] + 1 != comb[i + 1])
			comb[i]++;
		if ((comb[i] + 1 == comb[i + 1] || comb[i] == '9'))
			i--;
		else
		{
			while (i < n - 1)
			{
				i++;
				comb[i] = comb[i - 1] + 1;
			}
		}
	}
	ft_putstr(comb, 0);
}

void	ft_print_combn(int n)
{
	char	comb[10];
	char	*p_comb;

	p_comb = comb;
	ft_init_comb(p_comb, n);
	ft_fill_comb(p_comb, n);
}

/* int	main(void)
{
	ft_print_combn(3);
	return (0);
} */
