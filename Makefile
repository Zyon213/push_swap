
NAME = push_swap

SRCS = bigsort.c errorcheck.c libft.c link.c moves.c \
		small_moves.c smallsort.c main.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean: 
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

