NAME := libftprintf.a

SRC := ft_printf.c utils.c specifiers.c specifiers_2.c utils_2.c
SRC_BONUS := ft_printf_bonus.c utils_bonus.c specifiers_bonus.c specifiers_2_bonus.c utils_2_bonus.c utils_3_bonus.c

OBJ := $(patsubst %.c, %.o, $(SRC))
OBJ_BONUS := ./bns/ft_printf_bonus.o ./bns/utils_bonus.o ./bns/specifiers_bonus.o ./bns/specifiers_2_bonus.o ./bns/utils_2_bonus.o ./bns/utils_3_bonus.o

CC := cc

CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -srv $(NAME) $?

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f bonus

re: fclean all

bonus: $(OBJ_BONUS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -srv $(NAME) $(OBJ_BONUS)
	@touch bonus

$(OBJ_BONUS):
	cd ./bns; $(CC) $(CFLAGS) -c -I ../ $(SRC_BONUS)

.PHONY=all clean fclean re
