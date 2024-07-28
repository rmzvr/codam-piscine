/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:10:20 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 12:46:47 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "values.h"
#include "program.h"

t_dict_e	*create_dict(int argc, char **argv)
{
	int			pathlen;
	char		*filepath;
	t_dict_e	*dictionary;

	if (argc == 2)
	{
		pathlen = ft_strlen(DATA_PATH) + ft_strlen(DEFAUlT_DATA_FILE) + 1;
		filepath = (char *)malloc(pathlen * sizeof(char));
		ft_strcpy(filepath, DATA_PATH);
		ft_strcat(filepath, DEFAUlT_DATA_FILE);
	}
	else
	{
		pathlen = ft_strlen(DATA_PATH) + ft_strlen(argv[1]) + 1;
		filepath = (char *)malloc(pathlen * sizeof(char));
		ft_strcpy(filepath, DATA_PATH);
		ft_strcat(filepath, argv[1]);
	}
	dictionary = (t_dict_e *)malloc(sizeof(t_dict_e) * MAX_DICT_ROWS);
	parse_dict(filepath, dictionary);
	trim_dict(dictionary);
	return (dictionary);
}
