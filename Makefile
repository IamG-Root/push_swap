NAME = push_swap
NAMEB = push_swap.a
CC = gcc
OPTIONS = -c
SRCS = main.c utils.c split_av.c swap.c sorting.c rotations.c reverse_rotations.c push.c sorting2.c get_next_line.c get_next_line_utils.c
SRCSB = utils.c split_av.c swap.c sorting.c rotations.c reverse_rotations.c push.c sorting2.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
PRINTF = libftprintf.a

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

all :		$(NAME)

$(NAME): $(OBJS)
	@make -C ./ft_printf
	@cp ./ft_printf/libftprintf.a .
	$(CC) $(OBJS) -o $(NAME) $(PRINTF)

$(NAMEB): $(OBJSB)

		ar rcs $(NAMEB) $(OBJSB)

bonus : $(NAMEB) $(OBJSB)
	@make -C ./ft_printf
	@cp ./ft_printf/libftprintf.a bonus
	@mv push_swap.a bonus
	@make -C ./bonus
	${RM} ${OBJSB}

clean:
	@make -C ./ft_printf clean
	@make -C ./bonus fclean
	${RM} ${OBJS}

fclean: clean
	rm -rf libftprintf.a
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re