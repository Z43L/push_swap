NAME = pushswap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

INCLUDES = -I. -I./LIBFT -I./FT_PRINTF 

LIBFT_DIR = ./LIBFT
PRINTF_DIR = ./FT_PRINTF


SRCS = algoorden.c main.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c sa.c sb.c ss.c
OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libprintf.a


all: subsystems $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

subsystems:
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re subsystems
