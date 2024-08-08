/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:24:53 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 13:21:03 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "values.h"
#include "program.h"

void	parse_dict(char *file, t_dict_e *dict)
{
	char	buffer[MAX_DICT_SIZE + 1];

	read_file_to_buffer(file, buffer);
	parse_buffer(buffer, dict);
}
