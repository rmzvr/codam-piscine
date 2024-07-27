/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:33:55 by rmzvr             #+#    #+#             */
/*   Updated: 2024/07/25 14:05:47 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(ft_strlen(src) * sizeof(char));
	i = 0;
	while (*src)
	{
		dest[i] = *src++;
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	char	*res;

	res = ft_strdup("abcde");
	printf("%s", res);
	free(res);
	return (0);
} */
