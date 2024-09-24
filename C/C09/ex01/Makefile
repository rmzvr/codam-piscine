TARGET_EXEC := libft.a

SRCS_DIR := ./srcs

SRCS := ./srcs/ft_putchar.c
OBJS := ./srcs/ft_putchar.o

all: $(TARGET_EXEC)

$(TARGET_EXEC): $(OBJS)
	ar rcs $(TARGET_EXEC) $(OBJS)

%.o: %.c
	cc -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean all

re: fclean all