CC = cc
CFLAGS = -Wall -Wextra -Werror $(MLX_CFLAGS)
LDFLAGS = $(MLX_LDFLAGS) -lXext -lX11 -lm

NAME = fractal
SRCS = image.c
OBJS = $(SRCS:.c=.o)
NIX = shell.nix

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

nix: $(NIX)
	nix-shell

.PHONY: all clean fclean re
