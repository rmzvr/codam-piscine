/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_three_digit_case.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:09:48 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 13:13:18 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "values.h"
#include "program.h"

int	handle_three_digit_case(char *str, char *f_str, t_dict_e *dict)
{
	if (!process_three_digits(str, f_str, dict))
		return (0);
	if (ft_strlen(str) > 3)
	{
		if (str[0] != '0' || str[1] != '0' || str[2] != '0')
		{
			if (!write_thousands_str(ft_strlen(str), 2, f_str, dict))
				return (0);
		}
		ft_strremove(str, 3);
		return (write_number(str, f_str, dict));
	}
	return (1);
}
