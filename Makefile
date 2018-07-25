# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/15 16:33:01 by eaptekar          #+#    #+#              #
#    Updated: 2018/07/24 16:32:32 by eaptekar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -I.
MLX		= -lmlx -framework OpenGL -framework AppKit
LIBFT	= ./libft/libft.a
SRC		= begin.c\
		  drawing.c\
		  parsing.c
OBJ		= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(LIBFT) $(OBJ) $(MLX)

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<
	@echo "Compiling ..."

$(LIBFT):
	@make -C libft

clean:
	@rm -rf $(OBJ)
	@make -C libft fclean	

fclean: clean
	@rm -rf $(NAME)

re: fclean all
