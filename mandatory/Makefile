SRC_PATH	=		./src/

H_SRC		=		./includes/ft_printf.h ./includes/libft.h

SRC			=		./src/ft_printf.c ./src/ft_uitoa.c ./src/ft_printf_utils.c

OBJ			=		$(SRC:.c=.o)

libft		=		libft.a

NAME		=		libftprintf.a

CFLAGS		=	-Wall -Wextra -Werror

.c.o:
			cc ${CFLAGS} -c -g3 $< -o ${<:.c=.o}

$(NAME):	${OBJ} ${H_SRC} ${libft}
			ar -rcsT $@ $^

all:		${NAME}

clean:
		rm -f ${OBJ}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re