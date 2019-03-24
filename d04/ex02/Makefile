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

NAME = Purify

COMPILER = clang++
WFLAG = -Wall -Werror -Wextra

SRC =	main.cpp \
		AssaultTerminator.cpp \
		Squad.cpp \
		TacticalMarine.cpp
all:
	$(COMPILER) $(WFLAG) $(SRC) -o $(NAME)

clean:
	

fclean: 
	rm -rf $(NAME)

re: fclean all
