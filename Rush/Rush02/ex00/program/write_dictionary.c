/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_dictionary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:21:21 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 12:42:02 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "values.h"
#include "lib.h"

int	write_dictionary(char *nbr, char *c_str, t_dict_e *dict)
{
	int	i;

	i = 0;
	while (i < MAX_DICT_ROWS)
	{
		if (ft_strcmp(dict[i].number, nbr) == 0)
		{
			ft_strcat(c_str, dict[i].word);
			ft_strcat(c_str, " ");
			return (1);
		}
		i++;
	}
	return (0);
}
