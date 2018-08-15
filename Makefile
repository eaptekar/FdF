# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/07 17:02:30 by eaptekar          #+#    #+#              #
#    Updated: 2018/08/15 15:32:01 by eaptekar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

CC		= gcc
FLAGS	= -Wall -Werror -Wextra

SRCS 	= main.c \
		  map.c \
		  transform.c \
		  image.c \
		  keys.c \
		  rotating.c \
		  parsing.c \
		  frame.c \


LIBFT 	= -L$(P_LFT) -lft
MLX 	= -lmlx -framework OpenGL -framework AppKit

SRC_DIR = srcs/
OBJ_DIR = obj/
I_INC 	= includes
I_LFT 	= libft/
P_LFT 	= libft

OC		=\033[0m
GCOL	=\033[32;05m
YCOL	=\033[33m

INC = $(addprefix -I,$(I_INC) $(I_LFT))
SRC = $(addprefix $(SRC_DIR),$(SRCS))
OBJ = $(addprefix $(OBJ_DIR),$(OBJS))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(P_LFT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)
	@echo "\n$(GCOL)$(NAME) is ready$(OC)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(GCOL)\c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -o $@ -c $^ $(INC)
	@echo -n ████████████
	@echo "$(OC)\c"

clean:
	@make -C $(P_LFT) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(YCOL)removing ./obj/$(OC)"

fclean: clean
	@make -C $(P_LFT) fclean
	@rm -f $(NAME)
	@echo "$(YCOL)$(NAME) removed$(OC)"

re: fclean all
