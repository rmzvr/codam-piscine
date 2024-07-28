/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_one_digit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:08:32 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 13:13:21 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "values.h"
#include "program.h"

int	process_one_digit(char *str, char *f_str, t_dict_e *dict)
{
	if (str[0] != '0')
	{
		if (!write_one_str(str, 0, f_str, dict))
			return (0);
	}
	return (1);
}
