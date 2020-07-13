# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 18:24:41 by wquirrel          #+#    #+#              #
#    Updated: 2019/09/20 20:12:59 by wquirrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strcmp.c ft_strlen.c \
	  ft_atoi.c ft_bzero.c ft_isalnum.c ft_strnlen.c\
	  ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memmove.c ft_memset.c \
	  ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c \
	  ft_strdup.c ft_strlcat.c ft_strncat.c ft_strncmp.c \
	  ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c \
	  ft_tolower.c ft_toupper.c \
	  ft_islower.c ft_isspace.c ft_isupper.c ft_revstr.c ft_countwords.c \
	  ft_ischar.c ft_wordlen.c \
	  \
	  ft_putchar.c ft_putstr.c ft_putendl.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_striter.c ft_strmap.c ft_striteri.c \
	  ft_strmapi.c ft_memalloc.c ft_memdel.c ft_putendl_fd.c \
	  ft_strclr.c ft_strjoin.c ft_strnequ.c ft_itoa.c ft_putnbr_fd.c \
	  ft_strdel.c ft_strequ.c ft_strnew.c ft_putnbr.c ft_strsub.c \
	  ft_strtrim.c ft_strsplit.c \
	  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	  ft_lstmap.c


OBJ = $(SRC:.c=.o) 

CFLAGS = -Wall -Wextra -Werror

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(HEADER)
	gcc $(CFLAGS) -c $<

clean:
	/bin/rm -f $(OBJ)

fclean:	clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
