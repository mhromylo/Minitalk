# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 17:21:53 by mhromylo          #+#    #+#              #
#    Updated: 2024/01/26 15:00:34 by mhromylo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = *.c

OBJECTS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = server client

BONUS = server_bonus client_bonus

LIBFTDIR = ./libft/
LIBFT = ./libft/libft.a

all: $(NAME)

server: server.c $(LIBFT)
	$(CC) $(CFLAGS) server.c $(LIBFT) -o server

client: client.c $(LIBFT)
	$(CC) $(CFLAGS) client.c $(LIBFT) -o client

server_bonus: server_bonus.c $(LIBFT)
	$(CC) $(CFLAGS) server_bonus.c $(LIBFT) -o server_bonus

client_bonus: client_bonus.c $(LIBFT)
	$(CC) $(CFLAGS) client_bonus.c $(LIBFT) -o client_bonus

$(LIBFT):
	make all -C $(LIBFTDIR)

clean :
		rm -f *.o
		rm -f $(LIBFTDIR)*.o
fclean: clean
		rm -f $(NAME) $(BONUS)
		rm -f $(LIBFTDIR)*.o $(LIBFTDIR)*.a
re: fclean all

bonus: server_bonus client_bonus
