/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_one_digit_case.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:11:32 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 14:43:06 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "values.h"
#include "program.h"

int	handle_one_digit_case(char *str, char *f_str, t_dict_e *dict)
{
	if (!process_one_digit(str, f_str, dict))
		return (0);
	if (ft_strlen(str) > 3)
	{
		if (!write_thousands_str(ft_strlen(str), 0, f_str, dict))
			return (0);
		ft_strremove(str, 1);
		return (write_number(str, f_str, dict));
	}
	return (1);
}
