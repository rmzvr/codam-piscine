/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:34:56 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 15:35:08 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "program.h"
#include "values.h"

int	main(int argc, char **argv)
{
	t_dict_e	*dictionary;
	char		*final_string;
	int			success;

	if (!validate_input(argc, argv))
		return (ft_show_error());
	dictionary = create_dict(argc, argv);
	final_string = create_final_string();
	if (!ft_is_only_zero(argv[argc - 1]))
		ft_strtrim_front(argv[argc - 1], '0');
	else
		ft_strcpy(argv[argc - 1], "0");
	success = write_number(argv[argc - 1], final_string, dictionary);
	if (success)
	{
		ft_strtrim_back(final_string, ' ');
		ft_putstr(final_string, 1);
	}
	else
		ft_putstr("Dict Error", 1);
	free(dictionary);
	free(final_string);
}
