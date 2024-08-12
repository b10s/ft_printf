NAME := libftprintf.a

SRC := ft_printf.c utils.c specifiers.c specifiers_2.c

OBJ := $(patsubst %.c, %.o, $(SRC))

CC := cc

#CFLAGS := -Wall -Wextra -Werror
CFLAGS := 

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -srv $(NAME) $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY=all clean fclean re

bonus: $(NAME)


main:
	$(CC) $(CFLAGS) ft_printf.c ./libft/libft.h -o exe

#TODO: run make libft and use it to compile printf
