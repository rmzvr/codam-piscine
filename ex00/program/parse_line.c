/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:20:07 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 13:20:17 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "values.h"

void	parse_line(char *buffer, int *i, t_dict_e *dict, int row)
{
	int	j;

	j = 0;
	while (buffer[*i] != ':')
	{
		dict[row].number[j] = buffer[*i];
		j++;
		(*i)++;
	}
	dict[row].number[j] = '\0';
	(*i)++;
	j = 0;
	while (buffer[*i] != '\n' && buffer[*i] != '\0')
	{
		dict[row].word[j] = buffer[*i];
		j++;
		(*i)++;
	}
	dict[row].word[j] = '\0';
}
