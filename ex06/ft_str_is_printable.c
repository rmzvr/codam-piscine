/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:56:10 by rzvir             #+#    #+#             */
/*   Updated: 2024/07/14 12:02:46 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= ' ' && str[i] <= '~')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/* int     main(void)
{
        char    src[] = "4";
        int	res;

	res = ft_str_is_printable(src);
        printf("%d", res);
        return (0);
} */
