/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_norminette.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchernia <tchernia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:00:44 by tchernia          #+#    #+#             */
/*   Updated: 2024/07/20 21:05:52 by tchernia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	char_len(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
	{
		counter++;
	}
	return (counter);
}

int	is_int(char c)
{
	if (c >= 49 && c <= 52)
		return (1);
	return (0);
}

int	is_valid_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && i != 0)
		{
			if (!is_int(str[i]))
				return (0);
		}
		else if (i % 2 != 0)
		{
			if (str[i] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_left(int count, char *row)
{
	int	i;

	i = 0;
	while (row[i] < row[i +1])
	{
		i++;
	}
	i++;
	if (i == count)
		return (1);
	return (0);
}

void	shift(char *str, int length)
{
	char	temp[5];
	int		i;

	i = 0;
	while (i < (length - 1))
	{
		temp[i] = str[i +1];
		i++;
	}
	temp[length] = '\0';
	temp[length - 1] = str[0];
	i = 0;
	while (i < length)
	{
		str[i] = temp[i];
		i++;
	}
}

/* void fix(int x, int y, char *matrix)
{
        while (x < 4)
        {
                while (y < 4)
                {
                        matrix[x][y] = y + '1';
                        y++;
		}
        }	
}*/

void	extract_left(char *str, char *temp)
{
	int	i;
	int	j;

	i = 16;
	j = 0;
	while (i <= 22 && str[i] != '\0')
	{
		if (str[i] > '0' && str[i] < '9')
		{
			temp[j] = str[i];
			j++;
		}
		i++;
	}
	temp[j] = '\0';
}

int	main(int argc, char *argv[])
{
	char	row1left[5];
	char	matrix[4][5];
	int		x;
	int		y;
	int		o;

	if (is_valid_arg(argv[argc - 1]) != 1 || char_len(argv[argc - 1]) != 31)
	{
		write(1, "Error\n", 5);
		return (1);
	}
	x = 0;
	y = 0;
	o = 0;
	extract_left(argv[argc - 1], row1left);
	while (x < 4)
	{
		while (y < 4)
		{
			matrix[x][y] = y + '1';
			y++;
		}
		matrix[x][y] = '\0';
		while (is_left((row1left[x] - '0'), matrix[x]) != 1)
		{
			shift(matrix[x], 4);
		}
		printf("%s\n", matrix[x]);
		x++;
		y = 0;
		o = 0;
	}
	return (0);
}
