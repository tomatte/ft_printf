DIR_SRC		=		./src

SRC			=		fill.c  ft_convert.c  \
					ft_printf.c printf_utils.c  \
					print_hex.c  print_int.c  \
					print_pointer.c  print_uint.c \
					fill_zeros.c

SRC_PATH	=		$(patsubst %.c,$(DIR_SRC)/%.c,$(SRC))

CFLAGS		=		-Wall -Wextra -Werror

OBJ			=		$(SRC:.c=.o)

LIBFT		=		libft.a

NAME		=		libftprintf.a

all: 		${NAME}

compile_src: $(DIR_OBJ)
	cc -g3 ${CFLAGS} -c ${SRC_PATH} -I.

$(LIBFT):
	$(MAKE) -C ./src/libft bonus

cp:
	cp ./src/libft/${LIBFT} ./${NAME}

$(NAME):	compile_src ${LIBFT} cp
	ar -rcs $@ $(OBJ)

bonus: all

clean:
	rm -f ${OBJ}; \
	$(MAKE) -C ./src/libft clean

fclean:		clean
	rm -rf $(NAME); \
	$(MAKE) -C ./src/libft fclean

re: 		fclean all

.PHONY: all clean fclean re