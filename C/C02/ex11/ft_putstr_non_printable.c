/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:00:47 by rmzvr             #+#    #+#             */
/*   Updated: 2024/08/17 17:29:17 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_ch_is_non_printable(char c)
{
	return (c < 32 || c == 127);
}

void	ft_dec_to_hex(int dec)
{
	int		i;
	int		temp_dec;
	char	hex[100];

	i = 0;
	while (dec != 0)
	{
		temp_dec = dec % 16;
		if (temp_dec < 10)
			temp_dec += 48;
		else
			temp_dec += 87;
		hex[i++] = temp_dec;
		dec = dec / 16;
	}
	if (i == 1)
		hex[i++] = '0';
	hex[i] = '\\';
	while (i >= 0)
		write(1, &hex[i--], 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (ft_ch_is_non_printable(*str))
			ft_dec_to_hex(*str);
		else
			write(1, str, 1);
		str++;
	}
}

/* int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	return (0);
} */
