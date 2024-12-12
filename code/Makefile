SRC			= so_long.c \
				create_array.c \
				graphics.c \
				hook_events.c \
				hook_loop.c

DIR			= obj/

OBJS		= ${addprefix ${DIR}, ${SRC:.c=.o}}

NAME		= so_long.a

AR			= ar rc

LIB			= ranlib

GCC			= cc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}
			@${GCC} ${CFLAGS} so_long.c ${NAME} -o game_of_life -L. -lmlx

${DIR}%.o: %.c
			@${GCC} ${CFLAGS} -Ilmx -c $< -o $@

${NAME}:	libft ${OBJS}
			@${AR} ${NAME} ${OBJS}
			@${LIB} ${NAME}

libft:
			@mkdir -p obj
			@make -C libft
			@cp libft/libftprintf.a ${NAME}

clean:
			@rm -f ${OBJS}
			@make -C libft clean

fclean:		clean
			@rm -f ${NAME}
			@rm -f game_of_life
			@make -C libft fclean

re:			fclean all

.PHONY:		all clean fclean re libft
