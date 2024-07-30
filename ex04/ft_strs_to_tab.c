/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:22:20 by rzvir             #+#    #+#             */
/*   Updated: 2024/07/30 13:18:54 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*arr;

	i = 0;
	arr = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (arr == NULL)
		return (NULL);
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[ac].str = 0;
	arr[ac].size = 0;
	arr[ac].copy = 0;
	return (arr);
}

/* #include <stdio.h>

int main(int argc, char **argv)
{
	int i;

	t_stock_str *res;
	t_stock_str *ptr;

	i = 0;
	res = ft_strs_to_tab(argc, argv);
	ptr = res;
	while (res->str != 0)
	{
		printf("size = %d\n", res->size);
		printf("str = %s\n", res->str);
		printf("copy = %s\n---------\n", res->copy);
		res++;
	}
	res = ptr;
	while (i < argc)
	{
		free(res[i].copy);
		i++;
	}
	free(res);
	return (0);
} */
