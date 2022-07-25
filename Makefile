DIR_SRC		=		./src

SRC			=		fill.c  ft_convert.c  \
					ft_printf.c printf_utils.c  \
					print_hex.c  print_int.c  \
					print_pointer.c  print_uint.c \
					fill_zeros.c

SRC_PRNT	=		$(patsubst %.c,$(DIR_SRC)/%.c,$(SRC))

H_SRC	=	./src/ft_printf.h

OBJS	=	${SRC_LIB:.c=.o} ${SRC_PRNT:.c=.o}

NAME	=	libftprintf.a

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

.c.o:
			cc ${FLAGS} -c $< -o ${<:.c=.o} -I.

$(NAME):	${OBJS} ${H_SRC}
			make -C ./src/libft
			mv ./src/libft/libft.a ./$(NAME)
			ar -rcs $@ $^

all: 		${NAME}

bonus:		${NAME}

clean:
			${RM} ${OBJS}
			make clean -C ./src/libft

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re