/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:14:31 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 12:38:12 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUES_H
# define VALUES_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct t_dict_e
{
	char	number[100];
	char	word[100];
}	t_dict_e;

# define DATA_PATH "./data/"
# define DEFAUlT_DATA_FILE "numbers.dict"
# define MAX_DICT_SIZE 8192
# define MAX_DICT_ROWS 200
# define MAX_OUTPUT_SIZE 8192

#endif
