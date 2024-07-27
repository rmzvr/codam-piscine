/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroenew <fgroenew@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:34:56 by fgroenew          #+#    #+#             */
/*   Updated: 2024/07/27 17:50:40 by fgroenew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_dictionary_entry
{
	char number[100];
	char word[100];
}	t_dictionary_entry;

int	write_dictionary(char *nbr, char *current_string, t_dictionary_entry *dictionary)
{
	int	i;

	i = 0;
	while (i < 50)
	{
		if (strcmp(dictionary[i].number, nbr) == 0)
		{
			ft_strcat(current_string, dictionary[i].word);
			ft_strcat(current_string, " ");
			return (1);
		}
		i++;
	}
	return (0);
}

void	create_thousands(char *str, int count)
{
	int i;

	str[0] = '1';
	i = 1;
	while (i < count)
		str[i++] = '0';
	str[i] = '\0';
}

int	write_thousands_string(int strlen, int minus, char *final_string, t_dictionary_entry *dictionary)
{
	char	*temp_str;

	temp_str = (char *)malloc((strlen - 1) * sizeof(char));
	create_thousands(temp_str, strlen - minus);
	if (!write_dictionary(temp_str, final_string, dictionary))
		return (0);
	free(temp_str);
	return (1);
}

int	write_hundred_string(char *str, char *final_string, t_dictionary_entry *dictionary)
{
	char	*temp_str;

	temp_str = (char *)malloc(2 * sizeof(char));
	temp_str[0] = str[0];
	temp_str[1] = '\0';
	if (!write_dictionary(temp_str, final_string, dictionary))
		return (0);
	free(temp_str);
	if (!write_dictionary("100", final_string, dictionary))
		return (0);
	return (1);
}

int	write_ten_string(char *str, int one_index, char *final_string, t_dictionary_entry *dictionary)
{
	char	*temp_str;

	temp_str = (char *)malloc(3 * sizeof(char));
		temp_str[0] = str[one_index];
	if (str[one_index] != '1')
		temp_str[1] = '0';
	else
		temp_str[1] = str[one_index + 1];
	temp_str[2] = '\0';
	if (!write_dictionary(temp_str, final_string, dictionary))
		return (0);
	free(temp_str);
	return (1);
}

int	write_one_string(char *str, int one_index, char *final_string, t_dictionary_entry *dictionary)
{
	char	*temp_str;

	temp_str = (char *)malloc(2 * sizeof(char));
	temp_str[0] = str[one_index];
	temp_str[1] = '\0';
	if (!write_dictionary(temp_str, final_string, dictionary))
		return (0);
	free(temp_str);
	return (1);
}

int	write_number(char *str, char *final_string, t_dictionary_entry *dictionary)
{
	int	strlen;

	strlen = ft_strlen(str);
	if (strlen % 3 == 0)
	{
		if (str[0] != '0')
		{
			if (!write_hundred_string(str, final_string, dictionary))
				return (0);
		}
		if (str[1] != '0')
		{
			if (!write_ten_string(str, 1, final_string, dictionary))
				return (0);
		}
		if (str[2] != '0' && str[1] != '1')
		{
			if (!write_one_string(str, 2, final_string, dictionary))
				return (0);
		}
		if (strlen > 3)
		{
			if (str[0] != '0' || str[1] != '0' || str[2] != '0')
			{
				if (!write_thousands_string(strlen, 2, final_string, dictionary))
					return (0);
			}
			ft_strremove(str, 3);
			return (write_number(str, final_string, dictionary));
		}
	}
	else if (strlen % 3 == 1)
	{
		if (str[0] != '0')
		{
			if (!write_one_string(str, 0, final_string, dictionary))
				return (0);
		}

		if (strlen > 3)
		{
			if (!write_thousands_string(strlen, 0, final_string, dictionary))
				return (0);

			ft_strremove(str, 1);
			return (write_number(str, final_string, dictionary));
		}
	}
	else if (strlen % 3 == 2)
	{
		if (!write_ten_string(str, 0, final_string, dictionary))
			return (0);
		if (str[1] != '0' && str[0] != '1')
		{
			if (!write_one_string(str, 1, final_string, dictionary))
				return (0);
		}

		if (strlen > 3)
		{
			if (!write_thousands_string(strlen, 1, final_string, dictionary))
				return (0);

			ft_strremove(str, 2);
			return (write_number(str, final_string, dictionary));
		}
	}
	return (1);
}

void	create_dict(char *file, t_dictionary_entry *dictionary)
{
	char	buffer[1024 + 1];
	long	bytes_read;
	int		fd;
	int		i;
	int		j;
	int		row;

	fd = open(file, O_RDONLY);

	bytes_read = read(fd, buffer, 1024);
	buffer[bytes_read] = '\0';

	row = 0;
	i = 0;
	while (buffer[i] && row < 50)
	{
		j = 0;
		while (buffer[i] != ':')
		{
			dictionary[row].number[j] = buffer[i];
			j++;
			i++;
		}
		dictionary[row].number[j] = '\0';
		i++;
		j = 0;
		while (buffer[i] != '\n')
		{
			dictionary[row].word[j] = buffer[i];
			j++;
			i++;
		}
		dictionary[row].word[j] = '\0';
		row++;
		i++;
	}
}

void	trim_dict(t_dictionary_entry *dictionary)
{
	int	i;

	i = 0;
	while (i < 50)
	{
		ft_strtrim_front(dictionary[i].number, '\n');
		ft_strtrim_back(dictionary[i].number, ' ');
		ft_strtrim_front(dictionary[i].word, ' ');
		ft_strtrim_back(dictionary[i].word, ' ');
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (!argc)
		return (0);
	if (!argv)
		return (0);

	char	*final_string;
	int		success;
	char	*filepath = "./rush02/ex00/numbers.dict";
	t_dictionary_entry	*dictionary;

	dictionary = (t_dictionary_entry *)malloc(sizeof(t_dictionary_entry) * 60);
	create_dict(filepath, dictionary);
	trim_dict(dictionary);
	final_string = (char *)malloc(1024 * sizeof(char));
	final_string[0] = '\0';
	success = write_number(argv[1], final_string, dictionary);
	if (success)
	{
		ft_strtrim_back(final_string, ' ');
		printf("%s\n", final_string);
	}
	else
		printf("Dict Error\n");
}
