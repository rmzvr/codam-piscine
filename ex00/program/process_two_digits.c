/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_two_digits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:08:10 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 13:13:24 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "values.h"
#include "program.h"

int	process_two_digits(char *str, char *f_str, t_dict_e *dict)
{
	if (!write_ten_str(str, 0, f_str, dict))
		return (0);
	if (str[1] != '0' && str[0] != '1')
	{
		if (!write_one_str(str, 1, f_str, dict))
			return (0);
	}
	return (1);
}
