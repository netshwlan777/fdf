
LIBFT = libft

MLX = minilibx

NAME = fdf

FFLAGS = -Wall -Wextra -Werror

LFLAGS = -L $(LIBFT) -lft

MLXFLAGS = -L $(MLX) -lmlx -framework OpenGL -framework AppKit

FILES = ./main.c ./map_check.c ./memory_allocation.c ./image.c ./draw.c ./init.c ./button_press.c ./change_coord.c

OBJS = $(FILES:%.c=%.o)

LIBFT2 = libft

MLX2 = minilibx

INCLUDES = includes

all: libft.a libmlx.a $(NAME)

libft.a:
	make -C $(LIBFT)

libmlx.a:
	make -C $(MLX)

$(NAME): $(OBJS)
	gcc $(FFLAGS) -o $(NAME) $(OBJS) $(LFLAGS) $(MLXFLAGS)

%.o: %.c
	gcc $(FFLAGS) -I $(LIBFT2) -I $(MLX2) -I $(INCLUDES) -o $@ -c $<

clean: 
	rm -rf $(OBJS)
	make -C $(LIBFT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
