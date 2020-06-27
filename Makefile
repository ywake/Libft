# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 15:19:36 by ywake             #+#    #+#              #
#    Updated: 2020/06/27 08:11:23 by ywake            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC=gcc
INCLUDE=-I./
CFLAGS = -Wall -Werror -Wextra $(INCLUDE)
SRCDIR = ./
SRC = ft_strlen.c ft_strlcpy.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
	ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strlcat.c\
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_memset.c ft_memcpy.c\
	ft_memchr.c ft_memccpy.c ft_bzero.c ft_memcmp.c ft_memmove.c ft_atoi.c\
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c
BONUS = ft_isupper.c ft_islower.c ft_isspace.c ft_min.c
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
