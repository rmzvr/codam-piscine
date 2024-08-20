/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:59:14 by rmzvr             #+#    #+#             */
/*   Updated: 2024/08/20 14:45:09 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
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
	if (to_find_len == 0)
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			if (j == to_find_len - 1)
			{
				return (&str[i - j]);
			}
			j++;
		}
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	dest[] = "|AABABB1BA11";
	char	src[] = "BBA";
	char	*res;

	res = ft_strstr(dest, src);
	if (res == NULL)
	{
		printf("ERROR");
		return (1);
	}
	else
	{
		printf("%s\n", res);
	}
	return (0);
} */
