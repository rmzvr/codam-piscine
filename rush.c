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
	return counter;
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
	while(str[i])
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
	while (row[i] < row[i+1])
	{
		i++;
	}

	i++;
	printf("i: %d c: %d\n", i, count);
	if (i  == count)
		return (1);
	return (0);
}

void shift(char *str, int length)
{
	char temp[5];
	int i;
	char first_char;

	i = 0;
	while (i < (length - 1))
	{
		temp[i] = str[i+1];
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

void	extract_left(char *str)
{
	int	i;

	i = 8;
	while (i <= 12)
	{
		str[i-8] = str[i];
		i++;	
	}
}

int	main(int argc, char* argv[])
{
	char	row1left;
	char	matrix[4][5];
	int x;
	int o;
	int y;

	o = 0;
	x = 0;
	y = 0;
	while (x < 4)
	{
   	        while (y < 4)
                {
                        matrix[x][y] = y + '1';
                        y++;
                }
		matrix[x][y] = '\0';
		// row1left = extract_left(argv[argc - 1]);
		// printf("%s", row1left);
		while (o != x)
		{
			shift(matrix[x], 4);
			o++;
		}
		o = 0;
		printf("%s\n", matrix[x]);
        	y = 0;
		x++;
	}
	//printf("%d", is_left(3, "2431"));
	/* int x;
	int y;

shift(matrix[x], 4);	x = is_valid_arg(argv[argc - 1]);
	y = char_len(argv[argc - 1]);

	if (x != 1 || y != 31)
	{
	 	write(1, "Error\n", 5);
	} */
	return (0);
}
