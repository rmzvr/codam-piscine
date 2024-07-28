/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:10:36 by rzvir             #+#    #+#             */
/*   Updated: 2024/07/28 14:33:01 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void    ft_show_tab(struct s_stock_str *par)
{
    while (par->str != 0)
	{
        ft_putnbr(par->size);
        write(1, "\n", 1);
        ft_putstr(par->str);
        write(1, "\n", 1);
        ft_putstr(par->copy);
        write(1, "\n", 1);
		par++;
	}
}

/* int main(int argc, char **argv)
{
	int i;

	t_stock_str *par;

	i = 0;
	par = ft_strs_to_tab(argc, argv);
    ft_show_tab(par);
	while (i < argc)
	{
		free(par[i].copy);
		i++;
	}
	free(par);
	return (0);
} */
