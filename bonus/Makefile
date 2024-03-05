NAME = checker
CC = gcc
OPTIONS = -c
SRCS = checker.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
PUSHSWAP = push_swap.a
PRINTF = libftprintf.a

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

all :		$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(PUSHSWAP) $(PRINTF)

clean:
	rm -rf push_swap.a
	rm -rf libftprintf.a
	${RM} ${OBJS}

fclean: clean
	rm -rf push_swap.a
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re