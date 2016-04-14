# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/16 13:06:21 by rfriscca          #+#    #+#              #
#    Updated: 2016/04/01 14:25:01 by rfriscca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
FRAMEWORK = -framework OpenGl -framework AppKit
LIBRARY = -Llibft/ -lft -Lminilibx_macos/ -lmlx
INCLUDES = -I libft/ -I minilibx_macos/
SRCS_DIR = srcs
SRCS = draw_line.c		\
	   ft_new_line.c	\
	   init_coo.c		\
	   main.c			\
	   seg.c			\
	   stock_file.c		\
	   test_file.c
OBJ = $(SRCS:.c=.o)
NAME = fdf
LIBFT_DIR = libft
OBJ_DIR = objs
MLX_DIR = minilibx_macos


all : LIBFT MLX $(NAME)

LIBFT :
	make -C $(LIBFT_DIR)

MLX :
	make -C $(MLX_DIR)

$(NAME) : $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBRARY) $(INCLUDES) $(FRAMEWORK)

%.o : $(SRCS_DIR)/%.c
	gcc $(FLAGS) -c $< $(INCLUDES)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
