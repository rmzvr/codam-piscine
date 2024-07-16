/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:59:14 by rmzvr             #+#    #+#             */
/*   Updated: 2024/07/15 23:24:02 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

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
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			while (to_find[j] != '\0')
                	{
				if (str[i + j] == to_find[j])
				{
					k++;
				}
                		j++;
			}
		}
		i++;
	}
	printf("%d", ft_strlen(to_find) - k);
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
