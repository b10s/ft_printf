NAME := libftprintf.a

SRC := ft_printf.c utils.c specifiers.c specifiers_2.c
SRC_BONUS := ft_printf_bonus.c utils_bonus.c specifiers_bonus.c specifiers_2_bonus.c

OBJ := $(patsubst %.c, %.o, $(SRC))
OBJ_BONUS := $(patsubst %.c, %.o, $(SRC_BONUS))

CC := cc

CFLAGS := -Wall -Wextra -Werror

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

bonus: $(OBJ_BONUS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -srv $(NAME) $(OBJ_BONUS)
	@touch bonus

.PHONY=all clean fclean re
