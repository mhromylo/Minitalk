# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 16:25:57 by mhromylo          #+#    #+#              #
#    Updated: 2024/01/19 12:04:12 by mhromylo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_atoi.c ft_itoa.c ft_bzero.c \
ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c \
ft_strlen.c ft_strncmp.c ft_strdup.c ft_strnstr.c ft_strrchr.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_striteri.c ft_strmapi.c ft_split.c ft_tolower.c ft_toupper.c ft_putnbr_fd.c \
ft_memchr.c ft_putchar_count.c ft_putstr_counter.c ft_putp.c ft_putnb.c ft_putnbu.c \
ft_puthex.c ft_printf.c

OBJECTS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a


all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean :
		rm -f *.o
fclean: clean
		rm -f $(NAME)
re: clean all
