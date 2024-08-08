/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:21:05 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 13:21:13 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "values.h"
#include "program.h"

void	parse_buffer(char *buffer, t_dict_e *dict)
{
	int	i;
	int	row;

	i = 0;
	row = 0;
	while (buffer[i] && row < MAX_DICT_ROWS)
	{
		parse_line(buffer, &i, dict, row);
		row++;
		if (buffer[i] == '\n')
			i++;
	}
}
