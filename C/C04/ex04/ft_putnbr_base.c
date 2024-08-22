/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:34:00 by rmzvr             #+#    #+#             */
/*   Updated: 2024/08/22 11:26:18 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_has_duplicates(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_convert_dec_to_base(char *res, int nbr, char *base)
{
	int	i;
	int	rem;
	int	base_len;

	i = 0;
	base_len = ft_strlen(base);
	if (nbr < 0)
		write(1, "-", 1);
	if (nbr == 0)
	{
		res[i] = base[i];
		i++;
	}
	while (nbr != 0)
	{
		rem = nbr % base_len;
		nbr = nbr / base_len;
		if (rem < 0)
			rem = rem * -1;
		res[i] = base[rem];
		i++;
	}
	res[i] = '\0';
}

void	ft_print_base(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	res[32];
	int		base_len;

	base_len = ft_strlen(base);
	if (base_len <= 1 || ft_has_duplicates(base))
		return ;
	ft_convert_dec_to_base(res, nbr, base);
	ft_print_base(res);
}

/* int	main(void)
{
	ft_putnbr_base(-1251251, "0123456789ABCDEF");
	return (0);
} */
