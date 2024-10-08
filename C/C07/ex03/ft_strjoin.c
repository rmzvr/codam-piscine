/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:21:05 by rmzvr             #+#    #+#             */
/*   Updated: 2024/07/27 18:10:27 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
	{
		i++;
	}
	return (i);
}

int	str_len_calc(char **strs, int sep_len, int size)
{
	int	i;
	int	str_len;

	i = 0;
	str_len = 0;
	while (i < size)
	{
		str_len += ft_strlen(strs[i]);
		i++;
	}
	if (size > 0)
		str_len += ((size - 1) * sep_len);
	else
		str_len = 0;
	return (str_len);
}

void	fill_res(char *res, char **strs, int size, char *sep)
{
	int	i;
	int	j;
	int	sep_len;

	i = 0;
	sep_len = ft_strlen(sep);
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			*res++ = strs[i][j];
			j++;
		}
		if (i < size - 1)
		{
			while (*sep)
			{
				*res++ = *sep++;
			}
			sep -= sep_len;
		}
		i++;
	}
	*res = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		sep_len;
	int		str_len;
	char	*res;

	sep_len = ft_strlen(sep);
	str_len = str_len_calc(strs, sep_len, size) + 1;
	res = (char *)malloc((str_len) * sizeof(char));
	fill_res(res, strs, size, sep);
	return (res);
}

/* #include <stdio.h>

int	main(void)
{
	char	*strs[5] = 
	{
		"abc1",
		"abc2",
		"abc3",
		"abc4",
		"abc5"
	};
	char	*res = ft_strjoin(5, strs, "-");
	if (res)
	{
		printf("%s\n", res);
		free(res);
	}
	return (0);
} */
