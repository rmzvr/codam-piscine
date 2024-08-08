/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:28:04 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 13:15:35 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "values.h"
#include "program.h"

int	write_number(char *str, char *f_str, t_dict_e *dict)
{
	int	strlen;

	strlen = ft_strlen(str);
	if (strlen == 0)
		return (1);
	if (strlen % 3 == 0)
		return (handle_three_digit_case(str, f_str, dict));
	else if (strlen % 3 == 2)
		return (handle_two_digit_case(str, f_str, dict));
	else if (strlen % 3 == 1)
		return (handle_one_digit_case(str, f_str, dict));
	return (1);
}
