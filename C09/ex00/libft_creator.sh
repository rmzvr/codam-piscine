#! /bin/bash

LIB_NAME="libft.a"
HEADER_FILE_NAME="libft.h"

touch $HEADER_FILE_NAME

echo "#pragma once
void    ft_putchar(char c);
void    ft_swap(int *a, int *b);
void    ft_putstr(char *str);
int     ft_strlen(char *str);
int     ft_strcmp(char *s1, char *s2);" > $HEADER_FILE_NAME

cc -c *.c

ar rcs $LIB_NAME *.o