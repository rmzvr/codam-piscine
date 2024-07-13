/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:55:35 by rzvir             #+#    #+#             */
/*   Updated: 2024/07/12 19:29:22 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || str[i] > 'z' || str[i] > 'Z' && str[i] < 'a')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/* int     main(void)
{
        char    src[] = "Hello";
        int	res;

	res = ft_str_is_alpha(src);
        printf("%d", res);
        return (0);
} */