#include <unistd.h>

void ft_print_numbers(void)
{
    char i;

    for (i = '0'; i <= '9'; i++)
    {
        write(1, &i, 1);
    }
}

int main(void)
{
    ft_print_numbers();

    return 0;
}