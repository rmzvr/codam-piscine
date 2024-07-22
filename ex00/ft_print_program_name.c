/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:05:56 by rzvir             #+#    #+#             */
/*   Updated: 2024/07/22 21:11:05 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*arg;
	int		i;

	i = 0;
	arg = argv[argc - 1];
	while (arg[i] != '\0')
	{
		write(1, &arg[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
