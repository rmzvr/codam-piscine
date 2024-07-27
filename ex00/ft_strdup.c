/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:33:55 by rmzvr             #+#    #+#             */
/*   Updated: 2024/07/27 18:11:30 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	dest = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (*src)
	{
		dest[i] = *src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* #include <stdio.h>

int	main(void)
{
	char	*res;

	res = ft_strdup("abcde");
	printf("%s", res);
	free(res);
	return (0);
} */
