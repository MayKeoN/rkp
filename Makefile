#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/18 00:55:19 by ymonfray          #+#    #+#              #
#    Updated: 2015/04/18 00:55:19 by ymonfray         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = rkp

SRC =	src/rkp_main.c			src/rkp_init.c			src/rkp_deal.c\
		src/rkp_display.c		

SRC2 =	src/rkp_2_main.c		src/rkp_2_init.c		src/rkp_2_deal.c\
		src/rkp_2_display.c		src/rkp_2_rate.c		src/rkp_2_key.c

INC = -I include/ -I ~/work/tools/sdl/include/SDL2/ -I ~/work/activities/get_next_line/others/get_next_line/libft/

HEAD = include/rkp.h include/rkp_def.h include/rkp_2_def.h ~/work/activities/get_next_line/others/get_next_line/libft/libft.h

LIB = -L ~/work/tools/sdl/lib/ -lSDL2 -lSDL2_image -lSDL2_ttf -L ~/work/activities/get_next_line/others/get_next_line/libft/ -lft

OBJ = $(SRC2:.c=.o)

FLAG = 

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ) $(INC) $(LIB)

%.o: %.c $(HEAD)
	$(CC) $(FLAG) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all