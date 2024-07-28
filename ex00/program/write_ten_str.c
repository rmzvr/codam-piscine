/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ten_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:30:29 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 12:47:38 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "values.h"
#include "program.h"

int	write_ten_str(char *str, int one_i, char *f_str, t_dict_e *dict)
{
	char	*temp_str;

	temp_str = (char *)malloc(3 * sizeof(char));
	temp_str[0] = str[one_i];
	if (str[one_i] != '1')
		temp_str[1] = '0';
	else
		temp_str[1] = str[one_i + 1];
	temp_str[2] = '\0';
	if (!write_dictionary(temp_str, f_str, dict))
		return (0);
	free(temp_str);
	return (1);
}
