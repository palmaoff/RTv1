NAME =	RTv1

SRC =   main.c \
		alg.c \
		cone.c \
		cylinder.c \
		ft_atof.c \
		ft_htoi.c \
		init_color.c \
		init_vec.c \
		parser_main.c \
		plane.c \
		rotate.c \
		vec_dot.c \
		vec_norm.c \
		vec_sum.c \
		vec_sub.c \
		vec_scale.c \
		sphere.c \
		light.c

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

CC = gcc
FLAGS = -O3 `sdl2-config --cflags`
LDFLAGS  = `sdl2-config --libs` -lm
INK = -I ./includes

GNL = ./getnextline
GNL_INK = -I ./getnextline

LIB = ./libft
LIB_INK = -I ./libft
LIBFT =	libft/libft.a

SDL_INK	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
			-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
			-I./frameworks/SDL2_image.framework/Versions/A/Headers \
			-I./frameworks/SDL2_mixer.framework/Headers \
			-F./frameworks/

SDL_LNK =	-framework SDL2 \
			-rpath ./frameworks \
			-framework SDL2_ttf \
			-framework SDL2_image \
			-framework SDL2_mixer \
			-framework OpenGL \
			-framework AppKit \
			-F./frameworks \

SRCDIR	= ./src/
INKDIR	= ./includes/
OBJDIR	= ./obj/

all: $(NAME) 

$(NAME): obj $(LIBFT) $(OBJ)
		@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LDFLAGS)
		@echo "\033[32m- RTv1 compiled\033[0m"

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c ./includes/RTv1.h
		$(CC) $(FLAGS) $(INK) $(LIB_INK)  -c $< -o $@

$(LIBFT): ./libft
	@make -C $(LIB)
	@echo "\033[32m- libft compiled\033[0m"

clean:
		@rm -f $(OBJ)
		@make -C $(LIB) clean
		@echo "\033[31m- RTv1 object files removed\033[0m"

fclean: clean
		@rm -f $(NAME)
		@echo "\033[31m- libmlx.a removed\033[0m"
		@make -C $(LIB) fclean
		@echo "\033[31m- libft.a removed\033[0m"

re: fclean all

.PHONY : all, re, clean, fclean
