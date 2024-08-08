/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hundred_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:31:15 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 12:42:32 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "values.h"
#include "program.h"

int	write_hundred_str(char *str, char *f_str, t_dict_e *dict)
{
	char	*temp_str;

	temp_str = (char *)malloc(2 * sizeof(char));
	temp_str[0] = str[0];
	temp_str[1] = '\0';
	if (!write_dictionary(temp_str, f_str, dict))
		return (0);
	free(temp_str);
	if (!write_dictionary("100", f_str, dict))
		return (0);
	return (1);
}
