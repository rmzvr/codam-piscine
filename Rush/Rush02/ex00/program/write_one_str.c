/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_one_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:29:15 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 12:43:54 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "values.h"
#include "program.h"

int	write_one_str(char *str, int one_i, char *f_str, t_dict_e *dict)
{
	char	*temp_str;

	temp_str = (char *)malloc(2 * sizeof(char));
	temp_str[0] = str[one_i];
	temp_str[1] = '\0';
	if (!write_dictionary(temp_str, f_str, dict))
		return (0);
	free(temp_str);
	return (1);
}
