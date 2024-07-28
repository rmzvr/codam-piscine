/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:25:47 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 12:41:22 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "values.h"

void	trim_dict(t_dict_e *dict)
{
	int	i;

	i = 0;
	while (i < MAX_DICT_ROWS)
	{
		ft_strtrim_front(dict[i].number, '\n');
		ft_strtrim_back(dict[i].number, ' ');
		ft_strtrim_front(dict[i].word, ' ');
		ft_strtrim_back(dict[i].word, ' ');
		i++;
	}
}
