#include <unistd.h>

void ft_print_reverse_alphabet(void)
{
    char i;

    for (i = 'z'; i >= 'a'; --i)
    {
        write(1, &i, 1);
    }
}

int main(void)
{
    ft_print_reverse_alphabet();

    return 0;
}