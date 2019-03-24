# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juochen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 14:33:37 by juochen           #+#    #+#              #
#    Updated: 2019/01/21 12:36:43 by juochen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = SI

COMPILER = clang++
WFLAG = -Wall -Werror -Wextra -fsanitize=address
HEADER = -I /includes

NCURSES_LINK = -lncurses

SRC_DIR = srcs
SRC =	main.cpp \
		GameMaster.class.cpp \
		Projectile.class.cpp \
		Player.class.cpp \
		Alien.class.cpp \
		AGameObject.class.cpp \
		Space.class.cpp \
		Bomb.class.cpp
SRCS =	$(addprefix $(SRC_DIR)/, $(SRC))

all:
	$(COMPILER) $(WFLAG) $(NCURSES_LINK) $(HEADER) $(SRCS) -o $(NAME)

clean:
	

fclean: 
	rm -rf $(NAME)

re: fclean all
