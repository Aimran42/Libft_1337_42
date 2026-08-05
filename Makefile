# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 13:18:33 by momahdam          #+#    #+#              #
#    Updated: 2025/10/26 17:30:29 by momahdam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =  ft_atoi.c \
	ft_isprint.c \
	ft_memmove.c \
	ft_strmapi.c \
	ft_toupper.c \
	ft_bzero.c \
	ft_itoa.c \
	ft_memset.c \
	ft_strdup.c \
	ft_strncmp.c \
	ft_calloc.c \
	ft_putchar_fd.c \
	ft_striteri.c \
	ft_strnstr.c \
	ft_isalnum.c \
	ft_putendl_fd.c \
	ft_strjoin.c \
	ft_strrchr.c \
	ft_isalpha.c \
	ft_memchr.c \
	ft_putnbr_fd.c \
	ft_strlcat.c \
	ft_strtrim.c \
	ft_isascii.c \
	ft_memcmp.c \
	ft_putstr_fd.c \
	ft_strlcpy.c \
	ft_substr.c \
	ft_isdigit.c \
	ft_memcpy.c \
	ft_split.c \
	ft_strlen.c \
	ft_tolower.c \
	ft_strchr.c

BONUS_SRCS = ft_lstlast_bonus.c \
	ft_lstmap_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstsize_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
HEADER = libft.h

all : $(NAME)
$(NAME) : $(OBJS)

bonus: $(BONUS_OBJS)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $<
	ar rcs $(NAME) $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY : clean
