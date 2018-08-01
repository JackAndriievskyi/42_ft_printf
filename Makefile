#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yandriie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/21 09:11:17 by yandriie          #+#    #+#              #
#    Updated: 2018/08/01 08:42:18 by yandriie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC_FILES = ft_getchar.c ft_getdata.c ft_gethex.c ft_getoctal.c ft_getpercent.c ft_getsdecimal.c ft_getspecsize.c ft_getstr.c ft_getudecimal.c ft_getwidthprec.c ft_makeflags.c ft_makehasho.c ft_makehashx.c ft_makeminus.c ft_makeplus.c ft_makeprec.c ft_makespace.c ft_makewidth.c ft_makezero.c ft_odhtostr.c ft_printf.c ft_unifuncs.c
SRC_PATH = sources/
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))

OBJ_PATH = objectives/
OBJ = $(addprefix $(OBJ_PATH), $(SRC_FILES:.c=.o))

HDR_FILES = ft_getdata.h ft_iprintf.h ft_makeflags.h ft_nums.h ft_printf.h ft_unifuncs.h
HDR_PATH = includes/
HDR = $(addprefix $(HDR_PATH), $(HDR_FILES))

CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(HDR_PATH)

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ)
	ar rs $(NAME) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HDR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	/bin/rm -fdR $(OBJ_PATH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all