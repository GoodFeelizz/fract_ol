# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: togomez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/24 16:12:04 by togomez           #+#    #+#              #
#    Updated: 2024/10/11 12:04:23 by togomez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
		utils_text.c \
		utils_number.c \
		converts.c \

OBJ = $(SRC:.c=.o)

HEADER = libftprintf.h

CFLAGS = -Werror -Wextra -Wall

NAME = libftprintf.a

all:	 $(NAME)

$(NAME): $(OBJ)
		 ar -crs $@ $^

%.o: %.c $(HEADER)
		cc $(CFLAGS) $< -c -o $@

clean:
		rm -f $(OBJ) $(BOBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
