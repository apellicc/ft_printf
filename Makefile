# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apellicc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/09 00:57:42 by apellicc          #+#    #+#              #
#    Updated: 2016/08/09 01:05:52 by apellicc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = *.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
		make -C libft/
		mv libft/libft.a ./$(NAME)
		gcc -c $(FLAG) $(SRC) -I ./
		ar rv $(NAME) $(OBJ)
		ranlib $(NAME)


clean :
		make clean -C libft/
		rm -rf $(OBJ)

fclean : clean
		make fclean -C libft/
		rm -rf $(NAME)

re : fclean all
