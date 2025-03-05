NAME = fractol

LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a
MLX = minilibx-linux/libmlx.a

CC = cc -g
MLXFLAGS = -L minilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11

SRCS = main.c\
	   key_events.c\
	   error_handling.c\
	   init_program.c\
	   color.c\
	   fractals.c\
	   ft_atod.c\
	   helper.c\

HEADERS = fractol.h

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

ifdef CHECK
CFLAGS += -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) $(LIBFT) $(FT_PRINTF) $(MLX) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I./mlx_linux -I. -c $< -o $@

$(LIBFT):
	@make -j8 -C libft/ all

$(FT_PRINTF):
	@make -j8 -C ft_printf/ all

$(MLX):
	@make -j8 -C minilibx-linux/ all

clean:
	rm -f $(OBJS)
	@make -C libft/ clean
	@make -C minilibx-linux/ clean
	@make -C ft_printf/ clean
	
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(FT_PRINTF)
	rm -f $(MLX)

re: fclean all

.PHONY: all fclean clean re