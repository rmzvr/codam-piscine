/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_thousands_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:32:00 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 12:45:01 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "values.h"
#include "program.h"

int	write_thousands_str(int strlen, int m, char *f_str, t_dict_e *dict)
{
	char	*temp_str;

	temp_str = (char *)malloc((strlen - 1) * sizeof(char));
	create_thousands(temp_str, strlen - m);
	if (!write_dictionary(temp_str, f_str, dict))
		return (0);
	free(temp_str);
	return (1);
}
