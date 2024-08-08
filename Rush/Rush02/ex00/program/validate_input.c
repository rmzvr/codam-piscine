/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:49:27 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 14:54:30 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	validate_input(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		return (0);
	if (!ft_str_is_numeric(argv[argc - 1]))
		return (0);
	return (1);
}
