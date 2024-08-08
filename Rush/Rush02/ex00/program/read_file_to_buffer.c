/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_to_buffer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:20:37 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/28 13:20:44 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "values.h"

long	read_file_to_buffer(char *file, char *buffer)
{
	int		fd;
	long	bytes_read;

	fd = open(file, O_RDONLY);
	bytes_read = read(fd, buffer, MAX_DICT_SIZE);
	buffer[bytes_read] = '\0';
	close(fd);
	return (bytes_read);
}
