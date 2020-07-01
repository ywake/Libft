# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 15:19:36 by ywake             #+#    #+#              #
#    Updated: 2020/07/01 14:18:12 by ywake            ###   ########.fr        #
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
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
	ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ= $(SRC:%.c=%.o)
OBJBONUS= $(BONUS:%.c=%.o)

.PHONY: all $(NAME) clean fclean re bonus

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJBONUS)
	ar rcs $(NAME) $(OBJ) $(OBJBONUS)

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
