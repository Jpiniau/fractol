NAME = fractol

FLAGS = -Wall -Werror -Wextra

LIBX = -lmlx -framework OpenGL -framework Appkit

SRC_PATH = ./src/

SRC_NAME =	main.c\
			ft_draw.c\
			mandelbrot.c\
			cubic_mandelbrot.c\
			quadric_mandelbrot.c\
			quintic_mandelbrot.c\
			julia.c\
			julia_cubic.c\
			julia_quadric.c\
			julia_quintic.c\
			burning_ship.c\
			julia_burning_ship.c\
			bird.c\
			julia_bird.c\
			ft_pixel_put.c\
			ft_init.c\
			color.c\
			ft_mouse_hook.c\
			motion_hook.c\
			apply_zoom.c\
			ft_reset.c\
			ft_change.c\
			ft_menu.c\
			ft_menu_shell.c
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH = ./obj/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: lib $(NAME)

lib:
	@make -C libft/

$(NAME) : $(OBJ)
	gcc $(FLAGS) -o $@ $^ -L libft/ -lft $(LIBX) -lm

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	gcc $(FLAGS) -o $@ -c $< -I libft/includes -I include/.

clean :
	rm -rf $(OBJ_PATH)

fclean : clean
	rm -rf $(NAME)

re : fclean all
