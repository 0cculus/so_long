# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 10:30:28 by brheaume          #+#    #+#              #
#    Updated: 2023/04/25 14:31:09 by brheaume         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strlen.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_memset.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_bzero.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putnbendl_fd.c \
		ft_xfree.c \
		ft_strcombine.c \
		ft_isstrdigit.c \
		get_next_line.c \
		get_next_line_utils.c

OBJ = ${SRC:.c=.o}

CC = clang
CFLAGS = -Wextra -Wall -Werror -c

ARCHIVE = ar rc $(NAME)

LIBERATE = rm -f

$(NAME): $(OBJ)
	$(ARCHIVE) $(OBJ)
	@echo "\nLibft Archived\n"

all:$(NAME)

clean:
	$(LIBERATE) $(OBJ)
	@echo "\nLibft Liberated\n"

fclean: clean
	$(LIBERATE)  $(NAME)
	@echo "\nComplete Liberation\n"

re: fclean all
