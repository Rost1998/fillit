# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 20:25:03 by rtulchiy          #+#    #+#              #
#    Updated: 2017/11/19 10:21:10 by rtulchiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = main.o ft_error.o tetriminos.o checker_of_size.o checker_of_tetriminos.o\
		arrlen.o nearest_sqrt.o structnew.o coordinates.o fill_array_of_struct.o places.o\
		letsgo.o increment.o coord.o

INCLUDES = fillitlib.h
NAME = fillit
CFLAGS = -Wall -Wextra -Werror
DIR = libft

%.o: %.c $(INCLUDES)
	gcc $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(DIR)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -L. $(DIR)/libft.a
clean:
	make clean -C $(DIR)
	rm -f $(OBJ)
fclean: clean
	make fclean -C $(DIR)
	rm -f $(NAME)
re: fclean all