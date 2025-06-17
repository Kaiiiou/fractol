# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kai-iou <kai-iou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 14:21:15 by amarti            #+#    #+#              #
#    Updated: 2025/06/18 01:22:38 by kai-iou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -O2 $(INCLUDES)
RM		=	rm -f
CLONE	=	git clone

libft_url = https://github.com/Kaiiiou/42-libft.git

# === LIBFT ===
libft		= libft
LIBFT	=	$(libft)/libft.a

# === MLX42 ===
MLX42		= MLX42
MLX42_LIB	= $(MLX42)/build/libmlx42.a
MLX42_LIBS	= -ldl -L/opt/homebrew/lib -lglfw -pthread -lm

# === INCLUDES ===
INCLUDES = -I . -I libft -I $(MLX42)/include

# === SOURCES ===
SRC		=	main.c \
			utils.c \
			mandelbrot.c \
			julia.c \
			events.c

OBJ		=	$(SRC:.c=.o)

# === RULES ===

all: $(NAME)

$(MLX42_LIB):
	cmake $(MLX42) -B $(MLX42)/build -DCMAKE_C_FLAGS="-Wno-deprecated-ofast" && make -C $(MLX42)/build -j4

$(NAME): $(libft) $(MLX42_LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX42_LIB) $(MLX42_LIBS)

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
	$(RM) -rf $(MLX42)/build

re: fclean all

.PHONY: all clean fclean re