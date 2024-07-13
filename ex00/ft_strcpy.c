/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:54:33 by rzvir             #+#    #+#             */
/*   Updated: 2024/07/12 19:28:36 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	char	dest[10];
	char	src[] = "Hello";
	char	*res;
	int	i;

	i = 0;
	res = ft_strcpy(dest, src);
	while (res[i] != '\0')
	{
		printf("%c", res[i]);
	i++;
	}
	return (0);
} */