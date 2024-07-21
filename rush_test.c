/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:00:44 by tchernia          #+#    #+#             */
/*   Updated: 2024/07/21 16:17:44 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int char_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int is_int(char c)
{
	if (c >= 49 && c <= 52)
		return (1);
	return (0);
}

int is_valid_arg(char *str)
{
	int i;

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

int is_left(int count, char *row)
{
	int i;

	i = 0;
	while (row[i] < row[i + 1])
	{
		i++;
	}
	// i++;
	//  printf("IIIIIIII%d\n", i);
	if (i == count)
		return (1);
	return (0);
}

int is_right(int count, char *row)
{
	int i;
	int j;

	i = char_len(row) - 1;
	j = 0;
	while (row[i] < row[i - 1])
	{
		i--;
		j++;
	}
	j++;
	if (j == count)
		return (1);
	return (0);
}

void shift(char *str, int length)
{
	char temp[5];
	int i;

	i = 0;
	while (i < (length - 1))
	{
		temp[i] = str[i + 1];
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

void extract_left(char *str, char *temp)
{
	int i;
	int j;

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

void extract_right(char *str, char *temp)
{
	int i;
	int j;

	i = 24;
	j = 0;
	while (i <= 31 && str[i] != '\0')
	{
		// printf("!!!!!!!!!%c\n", str[i]);
		if (str[i] > '0' && str[i] < '9')
		{
			temp[j] = str[i];
			j++;
		}
		i++;
	}
	temp[j] = '\0';
}

char **generate_combinations()
{
	char digits[4] = {'1', '2', '3', '4'};
	char **combination;
	int i, j, k, l;
	int s;

	i = 0;
	s = 0;
	combination = (char **)malloc(24 * 8);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (j != i)
			{
				k = 0;
				while (k < 4)
				{
					if (k != i && k != j)
					{
						l = 0;
						while (l < 4)
						{
							if (l != i && l != j && l != k)
							{
								combination[s] = (char *)malloc(5);
								combination[s][0] = digits[i];
								combination[s][1] = digits[j];
								combination[s][2] = digits[k];
								combination[s][3] = digits[l];
								combination[s][4] = '\0';
								// printf("%s\n", combination[s]);
								s++;
							}
							l++;
						}
					}
					k++;
				}
			}
			j++;
		}
		i++;
	}
	return combination;
}

void remove(char *arr)
{
	int r = 0;
	printf("%s\n", arr[t]);
	char op = arr[t][0];
	while (r < 24)
	{
		// printf("arr[r][0] = %c\n", arr[r][0]);
		// printf("arr[t][0] = %c\n", arr[t][0]);
		if (arr[r][0] == op)
		{
			int yy;

			yy = 0;
			while (yy <= 3)
			{
				arr[r][yy] = '0';
				yy++;
			}
		}
		r++;
	}
}

int main(int argc, char *argv[])
{
	char row1left[5];
	char row1right[5];
	// char	matrix[4][5];
	int x;
	int y;
	int t;
	int r;
	if (is_valid_arg(argv[argc - 1]) != 1 || char_len(argv[argc - 1]) != 31)
	{
		write(1, "Error\n", 5);
		return (1);
	}
	x = 0;
	y = 0;
	t = 0;
	extract_left(argv[argc - 1], row1left);
	extract_right(argv[argc - 1], row1right);
	char **arr;
	arr = generate_combinations();
	while (x < 4)
	{
		while (t < 24)
		{
			// printf("RIGHT %d\n", row1right[x] - '0');
			// printf("%d\n", is_right((row1right[x] - '0'), arr[t]));
			//	printf("%d", (row1right[x] - '0'));
			// printf("%d", is_left((row1left[x] - '0'), arr[t]));
			if (is_left((row1left[x] - '0'), arr[t]) && is_right((row1right[x] - '0'), arr[t]))
			{
				r = 0;
				printf("%s\n", arr[t]);
				char op = arr[t][0];
				while (r < 24)
				{
					// printf("arr[r][0] = %c\n", arr[r][0]);
					// printf("arr[t][0] = %c\n", arr[t][0]);
					if (arr[r][0] == op)
					{
						int yy;

						yy = 0;
						while (yy <= 3)
						{
							arr[r][yy] = '0';
							yy++;
						}
					}
					r++;
				}
				// break;
			}
			t++;
		}
		t = 0;
		x++;

		/*
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
	*/
	}
	int iii;

	iii = 0;
	while (iii < 24)
	{
		// printf("-----");
		// printf("%s\n", arr[iii]);
		iii++;
	}
	return (0);
}
