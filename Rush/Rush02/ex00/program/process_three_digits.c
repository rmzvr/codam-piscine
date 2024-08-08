/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_three_digits.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:07:27 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 13:13:27 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "values.h"
#include "program.h"

int	process_three_digits(char *str, char *f_str, t_dict_e *dict)
{
	if (str[0] != '0')
	{
		if (!write_hundred_str(str, f_str, dict))
			return (0);
	}
	if (str[1] != '0')
	{
		if (!write_ten_str(str, 1, f_str, dict))
			return (0);
	}
	if (str[2] != '0' && str[1] != '1')
	{
		if (!write_one_str(str, 2, f_str, dict))
			return (0);
	}
	return (1);
}
