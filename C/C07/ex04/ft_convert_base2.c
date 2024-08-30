/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:35:38 by rmzvr             #+#    #+#             */
/*   Updated: 2024/08/26 14:15:32 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_atoi_base(char *str, char *base);

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

void	ft_convert_dec_to_base(char *res, int nbr, char *base, int base_len)
{
	int	i;
	int	rem;
	int	saved_nbr;

	i = 0;
	saved_nbr = nbr;
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
	if (saved_nbr < 0)
	{
		res[i++] = '-';
	}
	res[i] = '\0';
}

char	*ft_putnbr_base(int nbr, char *base)
{
	char	res[33];
	char	*malloc_res;
	int		i;
	int		j;
	int		base_len;

	j = 0;
	base_len = ft_strlen(base);
	malloc_res = (char *)malloc((32) * sizeof(char));
	ft_convert_dec_to_base(res, nbr, base, base_len);
	i = ft_strlen(res) - 1;
	while (i >= 0)
	{
		malloc_res[j] = res[i];
		i--;
		j++;
	}
	malloc_res[j] = '\0';
	return (malloc_res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec;
	char	*res;
	int		base_from_len;
	int		base_to_len;

	base_from_len = ft_strlen(base_from);
	base_to_len = ft_strlen(base_to);
	if (base_from_len <= 1
		|| base_to_len <= 1
		|| ft_has_duplicates(base_from)
		|| ft_has_duplicates(base_to))
		return (NULL);
	dec = ft_atoi_base(nbr, base_from);
	res = ft_putnbr_base(dec, base_to);
	return (res);
}

/* int	main(void)
{
	ft_convert_base("-425125", "01234", "01");
	return (0);
} */
