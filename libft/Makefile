# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eflorean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 11:13:27 by eflorean          #+#    #+#              #
#    Updated: 2020/01/21 16:17:33 by eflorean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	ft_isprint.c ft_memset.c ft_strcat.c ft_striteri.c ft_strnequ.c ft_toupper.c ft_itoa.c \
		ft_putchar.c ft_strchr.c ft_strjoin.c ft_strnew.c ft_memalloc.c ft_putchar_fd.c \
		ft_strclr.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_memccpy.c ft_putendl.c ft_strcmp.c \
		ft_strlen.c ft_strrchr.c ft_bzero.c ft_memchr.c ft_putendl_fd.c ft_strcpy.c ft_strmap.c \
		ft_strsplit.c ft_isalnum.c ft_memcmp.c ft_putnbr.c ft_strdel.c ft_strmapi.c ft_strstr.c \
		ft_isalpha.c ft_memcpy.c ft_putnbr_fd.c ft_strdup.c ft_strncat.c ft_strsub.c \
		ft_isascii.c ft_memdel.c ft_putstr.c ft_strequ.c ft_strncmp.c ft_strtrim.c \
		ft_isdigit.c ft_memmove.c ft_putstr_fd.c ft_striter.c ft_strncpy.c ft_tolower.c \
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
		ft_strndup.c ft_isspace.c ft_lstnewend.c ft_isgraph.c ft_sqrt.c

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $<

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY : all, re, clean, fclean
