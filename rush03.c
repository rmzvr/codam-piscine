#include "ft_putchar.c"

void	rush(int x, int y)
{
	int	count_x;
	int 	count_y;

	count_y = 0;
	while (count_y < y)
	{
		count_x = 0;
		while (count_x < x)
		{
			if (count_x == 0 && (count_y == 0 || count_y == y - 1))
			{	
				ft_putchar('A');
			}
			else if (count_x == x - 1 && (count_y == 0 || count_y == y - 1))
			{
				ft_putchar('C');
			}
			else if (count_x == 0 || count_y == 0 || count_x == x - 1 || count_y == y - 1)
			{
				ft_putchar('B');
			}
			else
			{
				ft_putchar(' ');
			}
			count_x++;
		}
		ft_putchar('\n');
		count_y++;
	}
}
