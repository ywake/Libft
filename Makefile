# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 15:19:36 by ywake             #+#    #+#              #
#    Updated: 2020/06/25 18:29:23 by ywake            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC=gcc
INCLUDE=-I./
CFLAGS = -Wall -Werror -Wextra $(INCLUDE)
SRCDIR = ./
SRC = ft_strlen.c ft_strlcpy.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_memset.c ft_memcpy.c ft_memchr.c
BONUS = ft_isupper.c ft_islower.c
OBJ= $(SRC:%.c=%.o)
OBJBONUS= $(BONUS:%.c=%.o)

.PHONY: all $(NAME) clean fclean re bonus

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJBONUS)
	ar rcs $(NAME) $(OBJBONUS)

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
