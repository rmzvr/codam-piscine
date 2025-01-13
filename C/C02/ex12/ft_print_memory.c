/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:43:56 by rmzvr             #+#    #+#             */
/*   Updated: 2024/09/29 12:31:28 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_convert_to_hex(unsigned long dec, int size, char *buffer)
{
	int		i;
	char	*hexadecimal_chars;

	i = 0;
	hexadecimal_chars = "0123456789abcdef";
	while (i < size)
	{
		buffer[i] = '0';
		i++;
	}
	buffer[i] = '\0';
	while (dec > 0)
	{
		i--;
		buffer[i] = hexadecimal_chars[dec % 16];
		dec /= 16;
	}
}

void	ft_print_char_full_address(char *ptr_to_address)
{
	char			buffer[17];
	unsigned long	address_in_decimal;

	address_in_decimal = (unsigned long)ptr_to_address;
	ft_convert_to_hex(address_in_decimal, 16, buffer);
	write(1, buffer, 17);
	write(1, ": ", 2);
}

void	ft_print_char_in_hex(char character)
{
	char		buffer[3];
	int			char_in_decimal;

	char_in_decimal = (unsigned long)character;
	ft_convert_to_hex(char_in_decimal, 2, buffer);
	write(1, buffer, 3);
}

void	ft_print_printable_characters(char character)
{
	if (character >= 32 && character <= 126)
	{
		write(1, &character, 1);
	}
	else
	{
		write(1, ".", 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				i;
	int				j;
	unsigned int	k;
	char			*char_addr;
	int				printed_lines;

	i = 0;
	j = 0;
	k = 0;
	char_addr = (char *)addr;
	printed_lines = (size / 16) + (size % 16 != 0);
	while (i < printed_lines)
	{
		ft_print_char_full_address(&(char_addr[k]));
		while (j < 16)
		{
			ft_print_char_in_hex(char_addr[k + j]);
			j++;
			if (k + j >= size)
				break ;
		}
		write(1, "\n", 1);
		i++;
		k = k + j;
		j = 0;
	}
	return (addr);
}

int	main(void)
{
	char	*str;
	void	*p_str;

	str = "Bonjour les aminches\t\n\tc\a est fo";
	p_str = (void *)str;
	ft_print_memory(p_str, 33);
	return (0);
}
