# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmostert <nmostert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 10:52:24 by nmostert          #+#    #+#              #
#    Updated: 2018/09/27 13:04:08 by nmostert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_PATH =../objs/
INCLUDES =../includes/

SRC_NAME=ft_atoi.c \
		ft_atol.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_islower.c \
		ft_isprint.c \
		ft_isupper.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_putstr_clr.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_isspace.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_wordcount.c \
		ft_stringput.c \
		ft_wordcount.c \
		ft_remspace.c \
		ft_strcopy.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_secondword.c \
		ft_lastdigits.c \
		get_next_line.c \
		ft_puttab.c \
		ft_puttab_fd.c \
		ft_containscol.c \
		ft_strndup.c \
		ft_containsrow.c \
		ft_strsplit_word.c \
		ft_lstnew.c \
		split.c \
		charpush.c \
		arraypush.c \
		arraylen.c \
		free_and_null.c \
		free2d.c \
		ft_putnbr_clr.c \

FLAGS= -Wall -Werror -Wextra
OBJ = $(SRC_NAME:%.c=%.o)
CC = gcc $(FLAGS)
FILES=$(addprefix $(OBJ_PATH), $(OBJ))


all: $(SRC_NAME)
ifeq ("$(wildcard $(FILES))","")
	$(CC) -I$(INCLUDES) -c $(SRC_NAME) -ggdb3
	mv *.o $(OBJ_PATH)
endif

clean:
	/bin/rm -f $(addprefix $(OBJ_PATH), $(OBJ))

re: clean all
