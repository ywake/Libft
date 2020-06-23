# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 15:19:36 by ywake             #+#    #+#              #
#    Updated: 2020/06/23 14:41:52 by ywake            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC=gcc
INCLUDE=-I./
CFLAGS = -Wall -Werror -Wextra $(INCLUDE)
SRCDIR = ./
SRC = ft_strlen.c ft_strlcpy.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c
BONUS = ft_isupper.c ft_islower.c
OBJ= $(SRC:%.c,%.o)

.PHONY: all clean fclean re

all: $(NAME)

.c.o:
	gcc $(FLAG) -c $< -o

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	runlib $(NAME)
	# ↑インデックスを作って高速化する
