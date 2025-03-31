NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft

SRCS = main.c pipex.c process.c paths.c utils.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
