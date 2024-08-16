/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:55:55 by rmzvr             #+#    #+#             */
/*   Updated: 2024/08/16 20:23:30 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char c)
{
	if (c < 'A' || c > 'z' || (c > 'Z' && c < 'a'))
		return (0);
	return (1);
}

int	ft_str_is_numeric(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_str_is_uppercase(char c)
{
	if (c < 'A' || c > 'Z')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (ft_str_is_alpha(str[i]))
	{
		if (!ft_str_is_uppercase(str[i]))
			str[i] -= 32;
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_str_is_alpha(str[i]) && ft_str_is_uppercase(str[i]))
			str[i] += 32;
		if (i > 0
			&& !ft_str_is_alpha(str[i - 1])
			&& !ft_str_is_numeric(str[i - 1])
			&& ft_str_is_alpha(str[i]))
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}

/* int	main(void)
{
	char str[] = "salut, Comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_strcapitalize(str);
	printf("%s", str);
	return (0);
} */
