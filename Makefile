CC = cc
CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap
BONUS = checker

MANDATORY_SRCS = \
	main.c \
	stack.c \
	parse.c \
	atoi_safe.c \
	error.c \
	index.c \
	ops_push.c \
	ops_rev_rotate.c \
	ops_rotate.c \
	ops_swap.c \
	sort_chunks.c \
	sort_small.c \
	split.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)

BONUS_SRCS = \
	checker_bonus.c \
	exec_instruction_bonus.c \
	ops_push_bonus.c \
	ops_rev_rotate_bonus.c \
	ops_rotate_bonus.c \
	ops_swap_bonus.c \
	get_next_line.c \
	get_next_line_utils.c \
		stack.c \
	parse.c \
	atoi_safe.c \
	error.c \
	index.c \
	ops_push.c \
	ops_rev_rotate.c \
	ops_rotate.c \
	ops_swap.c \
	sort_chunks.c \
	sort_small.c \
	split.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) -o $(NAME)

bonus: $(BONUS)

$(BONUS):  $(BONUS_OBJS)
	$(CC) $(CFLAGS)  $(BONUS_OBJS) -o $(BONUS)

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
