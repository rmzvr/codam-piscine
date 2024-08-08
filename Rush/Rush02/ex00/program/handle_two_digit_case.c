/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_two_digit_case.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:10:50 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 13:13:10 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "values.h"
#include "program.h"

int	handle_two_digit_case(char *str, char *f_str, t_dict_e *dict)
{
	if (!process_two_digits(str, f_str, dict))
		return (0);
	if (ft_strlen(str) > 3)
	{
		if (!write_thousands_str(ft_strlen(str), 1, f_str, dict))
			return (0);
		ft_strremove(str, 2);
		return (write_number(str, f_str, dict));
	}
	return (1);
}
