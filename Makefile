#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ireva <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/02 16:56:28 by ireva             #+#    #+#              #
#    Updated: 2017/03/10 16:57:23 by ireva            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I .
OBJECTS =						\
			./ft_printf.o		\
			./accuracy.o		\
			./f_flags.o			\
			./ft_itoa_base.o	\
			./ft_uitoa_base.o	\
			./s_flags.o			\
			./width.o			\
			./work_with_c.o		\
			./work_with_o.o		\
			./work_with_s.o		\
			./ft_atoi.o			\
			./lib_func.o		\
			./checkers.o		\
			./work_with_u.o		\
			./work_with_x.o		\
			./my_lib_func.o		\
			./work_with_p.o				
all : $(NAME)
$(NAME) : $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
%.o : ./%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)
clean :
	rm -rf $(OBJECTS)
	rm -rf *.c~
fclean : clean
	rm -rf $(NAME)
re : fclean all