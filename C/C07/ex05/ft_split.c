/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:53:41 by rmzvr             #+#    #+#             */
/*   Updated: 2024/08/31 21:08:54 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_any(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset || c == '\0')
			return (1);
		charset++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (count == 0 && !ft_any(*str, charset))
			count++;
		else if (ft_any(*str, charset) && !ft_any(*(str + 1), charset))
			count++;
		str++;
	}
	return (count);
}

int	ft_count_chars(char *str, char *charset)
{
	int	word_len;

	word_len = 0;
	while (!ft_any(*str, charset))
	{
		if (*str == '\0')
			break ;
		word_len++;
		str++;
	}
	return (word_len);
}

void	ft_write_word(char ***res, char **str, char *charset, int word_len)
{
	while (!ft_any(**str, charset))
	{
		if (**str == '\0')
			break ;
		***res = **str;
		(**res)++;
		(*str)++;
	}
	if (word_len != 0)
	{
		***res = '\0';
		**res -= word_len;
		(*res)++;
	}
	if (ft_any(**str, charset))
		(*str)++;
}

char	**ft_split(char *str, char *charset)
{
	int		word_count;
	int		word_len;
	char	**res;
	char	**start_res;

	word_count = ft_count_words(str, charset);
	res = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!res)
		return (0);
	start_res = res;
	while (*str != '\0')
	{
		word_len = ft_count_chars(str, charset);
		if (word_len != 0)
			*res = (char *)malloc((word_len + 1) * sizeof(char));
		ft_write_word(&res, &str, charset, word_len);
	}
	*res = NULL;
	return (start_res);
}

int	main(void)
{
	char	*str;
	char	*charset;
	char	**res;

	str = "a c ";
	charset = " ";
	res = ft_split(str, charset);
	while (*res)
	{
		printf("%s\n", *res);
		res++;
	}
	return (0);
}
