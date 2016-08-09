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
	#ft_printf.c\
		ft_is1.c\
		ft_is2.c\
		ft_is3.c\
		ft_itoa.c\
		ft_print_flag.c\
		ft_check.c

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
