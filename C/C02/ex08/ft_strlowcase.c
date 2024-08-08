/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:19:51 by rzvir             #+#    #+#             */
/*   Updated: 2024/07/12 19:34:53 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

/* int	main(void)
{
	char	src[5] = "Hello";
	char	*res;
	int		i;

	i = 0;
	res = ft_strlowcase(src);
	while (res[i] != '\0')
	{
		printf("%c", res[i]);
		i++;
	}
	return (0);
} */