/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:59:14 by rmzvr             #+#    #+#             */
/*   Updated: 2024/07/15 22:29:28 by rmzvr            ###   ########.fr       */
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
	int	counter;
	int	to_find_len;
       
	to_find_len = ft_strlen(to_find);
	counter = 0;

	while(*str)
	{
		if(counter != to_find_len - 1)
		{
			if(*str == *to_find)
			{
				to_find++;
				counter++;
			}
			else
			{
				to_find = to_find - counter;			
				counter = 0;
			}
			*str++;
		}
		else
		{
			return str - counter + 1;
		}
	}
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
