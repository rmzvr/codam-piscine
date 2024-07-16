/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:59:14 by rmzvr             #+#    #+#             */
/*   Updated: 2024/07/15 12:51:56 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (*src && i < nb)
	{
		dest[dest_len + i] = *src;
		i++;
		src++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

int	main(void)
{
	char	dest[] = "AAA";
	char	src[] = "BBB";
	char	*res;

	res = ft_strncat(dest, src, 2);
	printf("%s\n", res);
	return (0);
}
