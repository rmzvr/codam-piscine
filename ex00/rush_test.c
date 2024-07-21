/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:00:44 by tchernia          #+#    #+#             */
/*   Updated: 2024/07/21 22:09:12 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		char_len(char *str);
int		is_valid_arg(char *str);
void	extract_left(char *str, char *temp);
void	extract_right(char *str, char *temp);
char	**generate_combinations(void);
int		max_seen_left(char *arr);
int		max_seen_right(char *arr);
void	check_valid_combinations(char combinations[][5], int num_combinations);

int	main(int argc, char *argv[])
{
	char	row1left[5];
	char	row1right[5];
	int		x;
	int		y;
	int		t;
	int		i;
	char	sol[12][5];
	char	**arr;

	if (is_valid_arg(argv[argc - 1]) != 1 || char_len(argv[argc - 1]) != 31)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	x = 0;
	t = 0;
	y = 0;
	extract_left(argv[argc - 1], row1left);
	extract_right(argv[argc - 1], row1right);
	arr = generate_combinations();
	while (x < 4)
	{
		while (t < 24)
		{
			if (max_seen_left(arr[t]) == row1left[x] - '0'
				&& max_seen_right(arr[t]) == row1right[x] - '0')
			{
				i = 0;
				while (i < 4)
				{
					sol[y][i] = arr[t][i];
					i++;
				}
				sol[y][4] = '\0';
				y++;
			}
			t++;
		}
		t = 0;
		x++;
	}
	check_valid_combinations(sol, 12);
	return (0);
}
