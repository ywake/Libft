#############
# Functions #
#############

uniq = $(if $1,$(firstword $1) $(call uniq,$(filter-out $(firstword $1),$1)))

#############
# Variables #
#############

NAME	:= libft.a
B_NAME	:= libft.a
CC		:= gcc
INCLUDE	:= -I./
CFLAGS	:= -g -Wall -Werror -Wextra -std=c99 $(INCLUDE)

SRCS	:= ft_strlen.c ft_strlcpy.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_memset.c ft_memcpy.c ft_memchr.c ft_memccpy.c ft_bzero.c ft_memcmp.c ft_memmove.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
B_SRCS	:= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_strmap_bool_bonus.c ft_strcount_bonus.c ft_strndup_bonus.c free_set_bonus.c ft_strchr_i_bonus.c ft_lst_at_bonus.c ft_lst_reverse_bonus.c ft_lst_sort_bonus.c ft_strcmp_bonus.c set_rtn_bonus.c ft_lstndup_bonus.c ft_min_max_bonus.c ft_lstget_index_bonus.c ft_lstdrop_bonus.c contain_bonus.c

SRCDIRS	:= $(call uniq, $(dir $(SRCS) $(B_SRCS)))

OBJDIR	:= objs/
OBJDIRS	:= $(addprefix $(OBJDIR), $(SRCDIRS))
OBJS	:= $(addprefix $(OBJDIR), $(SRCS:%.c=%.o))
B_OBJS	:= $(addprefix $(OBJDIR), $(B_SRCS:%.c=%.o))
B_FLG	:= .bonus_flg

DSTRCTR	:= ./destructor.c

#################
# General rules #
#################

all: $(NAME)

$(NAME): $(OBJDIRS) $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(B_FLG)

$(B_FLG): $(OBJDIRS) $(OBJS) $(B_OBJS)
	ar rcs $(B_NAME) $(OBJS) $(B_OBJS)
	@touch $(B_FLG)

clean: FORCE
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME) $(B_NAME)
	$(RM) -r $(NAME).dSYM $(B_NAME).dSYM

re: fclean all

norm: FORCE
	@printf "$(RED)"; norminette | grep -v ": OK!" \
	&& exit 1 \
	|| printf "$(GREEN)%s\n$(END)" "Norm OK!"

$(OBJDIRS):
	mkdir -p $@

$(OBJDIR)%.o: %.c
	@printf "$(THIN)$(ITALIC)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(END)"

.PHONY: FORCE
FORCE:

###############
# Debug rules #
###############

$(DSTRCTR):
	curl https://gist.githubusercontent.com/ywake/793a72da8cdae02f093c02fc4d5dc874/raw/destructor.c > $(DSTRCTR)

sani: $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -o $(NAME) $(LIBS)

Darwin_leak: $(DSTRCTR) $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(DSTRCTR) -o $(NAME) $(LIBS)

Linux_leak: sani

leak: $(shell uname)_leak

bonus_sani: $(OBJDIRS) $(B_OBJS)
	$(CC) $(CFLAGS) -fsanitize=address $(B_OBJS) -o $(B_NAME) $(LIBS)

bonus_Darwin_leak: $(DSTRCTR) $(OBJDIRS) $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) $(DSTRCTR) -o $(B_NAME) $(LIBS)

bonus_Linux_leak: bonus_sani

bonus_leak: bonus_$(shell uname)_leak

##############
# Test rules #
##############

test: bonus
	$(MAKE) -C ../libft-test

##########
# Colors #
##########

END		= \e[0m
BOLD	= \e[1m
THIN	= \e[2m
ITALIC	= \e[3m
U_LINE	= \e[4m
BLACK	= \e[30m
RED		= \e[31m
GREEN	= \e[32m
YELLOW	= \e[33m
BLUE	= \e[34m
PURPLE	= \e[35m
CYAN	= \e[36m
WHITE	= \e[37m
