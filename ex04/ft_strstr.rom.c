/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.rom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:59:14 by rmzvr             #+#    #+#             */
/*   Updated: 2024/07/15 22:44:59 by rmzvr            ###   ########.fr       */
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

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	to_find_len;

	i = 0;
	j = 0;
	to_find_len = ft_strlen(to_find);
	while (str[i] != '\0')
	{
		if (j == to_find_len - 1)
		{
			return (&str[i - j]);
		}
		else if (str[i] == to_find[j])
		{
			j++;
		}
		else
		{
			j = 0;
		}
		i++;
	}
	return (NULL);
}

int	main(void)
{
	char	dest[] = "|AABABBBA";
	char	src[] = "BBA";
	char	*res;

	res = ft_strstr(dest, src);
	printf("%s\n", res);
	return (0);
}
