NAME = so_long

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft_src/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

HEADERS_LIST = so_long.h
HEADERS_DIRECTORY = ./inc/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

MLX = -L mlx -lmlx -framework OpenGL -framework AppKit

SOURCES_DIRECTORY = ./src/
SOURCES_LIST = 	main.c	errors.c	parse_checks.c	parse_utils.c \
				game.c	move_left_right.c	move_up_down.c 

SOURCES_BONUS_DIRECTORY = ./src_bonus/
SOURCES_BONUS_LIST = 	main_bonus.c	errors_bonus.c	parse_checks_bonus.c \
						parse_utils_bonus.c		game_bonus.c \
						move_left_right_bonus.c		move_up_down_bonus.c \
						enemy.c		parse_utils_bonus2.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
OBJECTS_DIRECTORY = ./objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

SOURCES_BONUS = $(addprefix $(SOURCES_BONUS_DIRECTORY), $(SOURCES_BONUS_LIST))
OBJECTS_DIRECTORY_B = ./objects_b/
OBJECTS_LIST_BONUS = $(patsubst %.c, %.o, $(SOURCES_BONUS_LIST))
OBJECTS_BONUS = $(addprefix $(OBJECTS_DIRECTORY_B), $(OBJECTS_LIST_BONUS))

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	make -s -C ./mlx
	$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) $(MLX) -o $(NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIRECTORY)

bonus: $(LIBFT) $(OBJECTS_DIRECTORY_B) $(OBJECTS_BONUS)
	make -s -C ./mlx
	$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS_BONUS) $(MLX) -o $(NAME)

$(OBJECTS_DIRECTORY_B):
	mkdir -p $(OBJECTS_DIRECTORY_B)

$(OBJECTS_DIRECTORY_B)%.o : $(SOURCES_BONUS_DIRECTORY)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	make clean -C ./mlx
	$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	rm -rf $(OBJECTS_DIRECTORY)
	rm -rf $(OBJECTS_DIRECTORY_B)

fclean: clean
	make clean -C ./mlx
	rm -f $(LIBFT)
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
	make re -C ./mlx