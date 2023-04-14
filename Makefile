# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 09:40:08 by brheaume          #+#    #+#              #
#    Updated: 2023/04/14 11:00:45 by brheaume         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c \
	  draw.c \
	  load.c \
	  error.c \
	  utils.c \
	  verify.c

OBJ = ${SRC:.c=.o}

CC = clang
CFGLAGS = -Wextra -Wall -Werror

LIB = -I include -lglfw -L "/USERS/${USER}/homebrew/opt/glfw/lib/"

LIBFT = libft.a
LIBDIR = libft/

MLXDIR = MLX42/
MLX = libmlx42.a

all: libft $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(LIBDIR)$(LIBFT) $(MLXDIR)$(MLX) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(LIBDIR)*.o

fclean: clean
	rm -f $(NAME)

libft:
	$(MAKE) -C $(LIBDIR)

re: fclean all

.PHONY: all libft
