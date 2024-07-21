/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:00:44 by tchernia          #+#    #+#             */
/*   Updated: 2024/07/21 19:13:38 by rzvir            ###   ########.fr       */
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

void remove_row(char **arr, int t)
{
    int r = 0;
    char op = arr[t][0];
    while (r < 24)
    {
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

int max_seen_left(char *arr)
{
    int max = 0;
    int i = 0;
    int count = 0;

    while (i < 4)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            count++;
        }
        i++;
    }
    return (count);
}

int max_seen_right(char *arr)
{
    int max = 0;
    int i = 3;
    int count = 0;

    while (i >= 0)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            count++;
        }
        i--;
    }
    return (count);
}

int main(int argc, char *argv[])
{
    char row1left[5];
    char row1right[5];
    // char matrix[4][4];
    int x;
    int y;
    int t;
    char sol[12][5];

    if (is_valid_arg(argv[argc - 1]) != 1 || char_len(argv[argc - 1]) != 31)
    {
        write(1, "Error\n", 5);
        return (1);
    }
    x = 0;
    t = 0;
    y = 0;

    extract_left(argv[argc - 1], row1left);
    extract_right(argv[argc - 1], row1right);
    char **arr;
    arr = generate_combinations();
    while (x < 4)
    {
        while (t < 24)
        {
            int row_left_number = (row1left[x] - '0');
            int row_right_number = (row1right[x] - '0');

            if (max_seen_left(arr[t]) == row_left_number && max_seen_right(arr[t]) == row_right_number)
            {
                int i = 0;
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

    int col = 0;
    while (col < 4)
    {
        int row = 0;
        while (row < 12)
        {
            int next_row = row + 1;
            while (next_row < 12)
            {
                if (sol[row][col] == sol[next_row][col])
                {
                    printf("Row with duplicate in column %d: ", col);
                    int print_col = 0;
                    while (print_col < 4)
                    {
                        printf("%c", sol[row][print_col]);
                        print_col++;
                    }
                    printf("\n");
                    break;
                }
                next_row++;
            }
            row++;
        }
        col++;
    }

    int i = 0;
    while (i < y)
    {
        // printf("sol[%d] = %s\n", i, sol[i]);
        i++;
    }

    return (0);
}
