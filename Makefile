NAME = push_swap

HDR = push_swap.h

SRCS = big_stack.c operation_small.c \
operation.c parsing_split.c parsing.c small_stack_five.c\
small_stack_four.c small_stack.c tag.c utils.c main.c

OBJS = ${SRCS:.c=.o}

LIBFT_AR = ./libft/libft.a 

INCLUDE = -I libft/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c ${HDR} ${LIBFT_AR} Makefile
	${CC} ${CFLAGS} -c $< -o $@ ${INCLUDE}

all: libft ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -Llibft -lft

libft:
	make -C libft

clean:
	rm -f ${OBJS}
	make clean -C libft

fclean: clean
	rm -f ${NAME}
	make fclean -C libft

re: fclean all

.PHONY: all libft clean fclean re