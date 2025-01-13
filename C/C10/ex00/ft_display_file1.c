/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:33:03 by rmzvr             #+#    #+#             */
/*   Updated: 2024/09/24 14:23:18 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_is_argument_invalid(int argc)
{
	if (argc == 1 || argc > 2)
	{
		return (1);
	}
	return (0);
}

int	ft_handle_invalid_argument(int argc)
{
	if (argc == 1)
	{
		ft_putstr("File name missing.");
	}
	else
	{
		ft_putstr("Too many arguments.");
	}
	return (0);
}

int	ft_display_file(char *file_name)
{
	char	buffer[1];
	char	read_bytes;
	int		file_descriptor;

	file_descriptor = open(file_name, 0);
	read_bytes = read(file_descriptor, buffer, sizeof(buffer));
	while (read_bytes > 0)
	{
		ft_putstr(buffer);
		read_bytes = read(file_descriptor, buffer, sizeof(buffer));
	}
	if (read_bytes == -1)
	{
		ft_putstr("Cannot read file.\n");
		close(file_descriptor);
		return (1);
	}
	close(file_descriptor);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*file_name;

	file_name = argv[1];
	if (ft_is_argument_invalid(argc))
	{
		ft_handle_invalid_argument(argc);
		return (1);
	}
	else
	{
		if (ft_display_file(file_name))
		{
			return (1);
		}
	}
	return (0);
}
