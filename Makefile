NAME := libftprintf.a

SRC := ft_printf.c

OBJ := $(patsubst %.c, %.o, $(SRC))

CC := cc

#CFLAGS := -Wall -Wextra -Werror
CFLAGS := 

all: $(NAME)

$(NAME): $(OBJ)
	ar -srv $(NAME) $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY=all clean fclean re

main:
	$(CC) $(CFLAGS) ft_printf.c ./libft/libft.h -o exe

#TODO: run make libft and use it to compile printf
