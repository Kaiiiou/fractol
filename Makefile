# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarti <amarti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 14:21:15 by amarti            #+#    #+#              #
#    Updated: 2025/06/16 20:40:51 by amarti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g $(INCLUDES)
RM		=	rm -f
CLONE	=	git clone

libft_url = https://github.com/Kaiiiou/42-libft.git

# === LIBFT ===
libft		= libft
LIBFT	=	$(libft)/libft.a

# === INCLUDES ===
INCLUDES = -I . -I libft

# === SOURCES ===
SRC		=	main.c \
			

OBJ		=	$(SRC:.c=.o)

# === RULES ===

all: $(NAME)

$(NAME): $(libft) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(libft):
	$(CLONE) $(libft_url) libft
	$(MAKE) -C $(libft)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(libft)

fclean: clean
	$(RM) $(NAME)
	$(RM) -rf $(libft)

re: fclean all

.PHONY: all clean fclean re