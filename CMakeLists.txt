cmake_minimum_required(VERSION 3.15)
project(RTv1 C)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_C_STANDARD 99)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(includes)
include_directories(src/getnextline)
include_directories(libft)

add_executable(RTv1 src/main.c
        src/main.c
        src/alg.c
        src/init_vec.c
        src/rotate.c
        src/vec_dot.c
        src/vec_norm.c
        src/vec_sum.c
        src/vec_sub.c
        src/vec_scale.c
        src/sphere.c
        src/light.c
        src/plane.c
        src/cylinder.c
        src/cone.c
        src/init_color.c
        src/parser/parser_main.c
        src/ft_htoi.c
        src/getnextline/get_next_line.c
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isgraph.c
        libft/ft_isprint.c
        libft/ft_isspace.c
        libft/ft_itoa.c
        libft/ft_lstadd.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_lstnewend.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_sqrt.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strndup.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtrim.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/ft_countwords.c
        src/ft_atof.c
        src/parser/parser_scene.c
        src/parser/parser_objects.c
        src/parser/parser_utils1.c
        src/parser/parser_file.c
        src/parser/parser_check_scene.c
        src/parser/parser_check_objects.c
        src/color_sum.c
        src/color_scale.c
        src/loop.c
        src/reflection.c
        src/parser/parser_utils2.c
        src/parser/parser_check_value.c
        src/help.c
        src/correct_queue.c
        src/check_color.c)

if (UNIX)
    target_link_libraries(RTv1 ${SDL2_LIBRARY} -lm)
else (UNIX)
    target_link_libraries(RTv1 ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2)
endif(UNIX)