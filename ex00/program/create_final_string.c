/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_final_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:19:49 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 12:47:01 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

char	*create_final_string(void)
{
	char	*final_string;

	final_string = (char *)malloc(MAX_OUTPUT_SIZE * sizeof(char));
	final_string[0] = '\0';
	return (final_string);
}
