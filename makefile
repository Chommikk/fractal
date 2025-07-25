CC = cc
CFLAGS = -Wall -Wextra $(MLX_CFLAGS)
LDFLAGS = $(MLX_LDFLAGS) -lmlx -lXext -lX11

NAME = fractal
SRCS = image.c
TEST = playground.c
OBJS = $(SRCS:.c=.o)
NIX = shell.nix

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

test: $(OBJS)
	$(CC) $(CFLAGS) $(TEST) $(LDFLAGS) -o $(NAME)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

nix: $(NIX)
	nix-shell

.PHONY: all clean fclean re
