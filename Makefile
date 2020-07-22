NAME =	RTv1

GNL_DIR = getnextline/
PARSER_DIR = parser/

SRCDIR	= ./src/
INKDIR	= ./includes/
OBJDIR	= ./obj/

GNL_INK = -I ./getnextline

PARSER_SRC = $(PARSER_DIR)parser_main.c \
             $(PARSER_DIR)parser_check_objects.c \
             $(PARSER_DIR)parser_check_scene.c \
             $(PARSER_DIR)parser_check_value.c \
             $(PARSER_DIR)parser_file.c \
             $(PARSER_DIR)parser_objects.c \
             $(PARSER_DIR)parser_scene.c \
             $(PARSER_DIR)parser_utils1.c \
             $(PARSER_DIR)parser_utils2.c

SRC =   main.c \
		alg.c \
		cone.c \
		color_scale.c \
		color_sum.c \
		cylinder.c \
		ft_atof.c \
		ft_htoi.c \
		help.c \
		init_color.c \
		init_vec.c \
		plane.c \
		reflection.c \
		rotate.c \
		vec_dot.c \
		vec_norm.c \
		vec_sum.c \
		vec_sub.c \
		vec_scale.c \
		sphere.c \
		light.c \
		loop.c \
		correct_queue.c \
		$(PARSER_SRC) \
		$(GNL_DIR)get_next_line.c

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

CC = gcc
FLAGS = -O3 `sdl2-config --cflags` -Wall -Wextra -Werror
LDFLAGS  = `sdl2-config --libs` -lm
INK = -I ./includes -I ./src/getnextline

LIB = ./libft
LIB_INK = -I ./libft
LIBFT =	libft/libft.a


all: $(NAME) 

$(NAME): obj $(LIBFT) $(OBJ)
		@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LDFLAGS)
		@echo "\033[32m- RTv1 compiled\033[0m"

obj:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(dir $(OBJ))

$(OBJDIR)%.o:$(SRCDIR)%.c ./includes/rtv1.h
		$(CC) $(FLAGS) $(INK) $(LIB_INK)  -c $< -o $@

$(LIBFT): ./libft
	@make -C $(LIB)
	@echo "\033[32m- libft compiled\033[0m"

clean:
		@#rm -f $(OBJ)
		@rm -rf $(OBJDIR)
		@make -C $(LIB) clean
		@echo "\033[31m- RTv1 object files removed\033[0m"

fclean: clean
		@rm -f $(NAME)
		@echo "\033[31m- libmlx.a removed\033[0m"
		@make -C $(LIB) fclean
		@echo "\033[31m- libft.a removed\033[0m"

re: fclean all

install:
		./install_SDL2.sh

.PHONY : all, re, clean, fclean
