/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:35:38 by rmzvr             #+#    #+#             */
/*   Updated: 2024/08/26 14:14:50 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

int	ft_is_base_digit(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if ((nb == 0 && power == 0) || power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, --power));
}

int	ft_convert_base_to_dec(char *res, int i, char *base, int minus_count)
{
	int	j;
	int	temp_i;
	int	result;
	int	base_len;

	i--;
	j = 0;
	result = 0;
	temp_i = 0;
	base_len = ft_strlen(base);
	while (i >= 0)
	{
		if (res[i] - 'A' + 10 >= 10)
		{
			temp_i = res[i] - 'A' + 10;
		}
		else
			temp_i = res[i] - '0';
		result = result + (temp_i * ft_recursive_power(base_len, j));
		i--;
		j++;
	}
	if (minus_count % 2 != 0)
		result = result * -1;
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int		result;
	int		minus_count;
	int		i;
	char	res[32];

	i = 0;
	minus_count = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_count++;
		str++;
	}
	while (ft_is_base_digit(*str, base))
	{
		res[i] = *str;
		str++;
		i++;
	}
	res[i] = '\0';
	result = ft_convert_base_to_dec(res, i, base, minus_count);
	return (result);
}
