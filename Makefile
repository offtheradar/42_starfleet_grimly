# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/12 10:31:31 by ysibous           #+#    #+#              #
#    Updated: 2018/04/12 11:05:39 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = grimly

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o

FILES = main.c
FILES += init_struct.c
FILES += load_file.c
FILES += map_error.c
FILES += print_map.c
FILES +=  queue.c
FILES += solve_map.c

SRC = $(addprefix src/, $(FILES))

all: $(NAME)

LIBFT = includes/libft/libft.a

mlibft.a: 
		make -C includes -C libft

$(NAME): mlibft.a
	$(CC) $(CFLAGS) $(NAME) $(SRC) $(LIBFT)
