# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 18:44:12 by olrudenk          #+#    #+#              #
#    Updated: 2019/03/11 13:49:34 by olrudenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS1 = -Wall -Wextra -Werror
FLAGS2 = -lmlx -framework OpenGL -framework Appkit
SRCS =	./srcs/main.c \
		./srcs/auxiliary.c \
		./srcs/create_map.c \
		./srcs/error_handling.c \
		./srcs/fdf.c \
		./srcs/free.c \
		./srcs/parse_map.c \
		./srcs/projections.c \
		./srcs/set_color.c \
		./srcs/bresenhams_algorithm.c \
		./srcs/rotation_matrixs.c \

INC = ./inc/fdf.h \
	  ./inc/keymap.h \

all: $(NAME)

OBJ = $(SRCS:.c=.o)

.PHONY : libft
libft:
	@make -C./libft

$(NAME): libft $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(FLAGS2) ./libft/libft.a
	@echo "\033[32mCompiling FDF...\033[0m"
	@echo "\033[34mFDF compilation is done. Have fun!\033[0m"

%.o: %.c $(INC)
	@gcc -o $@ -c $< $(FLAGS1)

clean:
	@make clean -C ./libft
	@rm -f $(OBJ)
	@echo "\033[32mDeleting object files... done.\033[0m"

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@echo "\033[32mDeleting fdf.exe.. done.\033[0m"

re: fclean all
