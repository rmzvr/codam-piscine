/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:05:56 by rzvir             #+#    #+#             */
/*   Updated: 2024/07/23 12:17:15 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void    swap(char **arg1, char **arg2)
{
    char    *temp;
    temp = *arg1;
    *arg1 = *arg2;
    *arg2 = temp;
}

int     ft_strcmp(char *s1, char *s2)
{
        while (*s1 || *s2)
        {
                if (*s1 != *s2)
                {
                        return (*s1 - *s2);
                }
                s1++;
                s2++;
        }
        return (0);
}

void sort(char    **argv, int argc)
{
    int    i;
    int    j;
    int    swapped;

    i = 0;
    j = 1;
    while (i < argc)
    {
        swapped = 0;
        while (j < argc - i - 1)
        {
            int diff = ft_strcmp(argv[j], argv[j + 1]); 
            if (diff > 0)
            {
                swap(&argv[j],&argv[i + 1]);
                swapped = 1;
            }
            j++;
        }
        if (swapped == 0)
            break;
        i++;
    }

}


int    main(void)
{
    int        i;
    int        j;

    char* argv[] = 
    {
      {""},
      {"test2"},
      {"test3"},
      {"test1"}
    };
    int argc = 4;

    sort(&argv, argc);
    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            write(1, &argv[i][j], 1);
            j++;
        }
        i++;
        write(1, "\n", 1);
    }
    return (0);
}
