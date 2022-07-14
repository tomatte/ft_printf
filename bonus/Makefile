DIR_SRC		=		./src

SRC			=		fill.c  ft_convert.c  \
					ft_printf.c printf_utils.c  \
					print_hex.c  print_int.c  \
					print_pointer.c  print_uint.c \

SRC_PATH	=		$(patsubst %.c,$(DIR_SRC)/%.c,$(SRC))

DIR_OBJ		=		objs

CFLAGS		=		-Wall -Wextra -Werror

#OBJ			=		$(patsubst %.c,./objs/%.o,$(SRC))

OBJ			=		$(SRC:.c=.o)

LIBFT		=		libft.a

NAME		=		libftprintf.a

all: 		${NAME}

compile_src: $(DIR_OBJ)
	cc ${CFLAGS} -c ${SRC_PATH} -I.

$(DIR_OBJ):
	mkdir -p $@

$(LIBFT):
	$(MAKE) -C ./src/libft bonus

move:
	mv ./src/libft/${LIBFT} ./${NAME}

$(NAME):	compile_src ${LIBFT} move
	ar -rcs $@ $(OBJ)

bonus: all

clean:
	rm -f ${OBJ}; \
	$(MAKE) -C ./src/libft clean

fclean:		clean
	rm -rf $(NAME); \
	$(MAKE) -C ./src/libft fclean

re: 		fclean all