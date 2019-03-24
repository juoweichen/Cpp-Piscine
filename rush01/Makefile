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

NAME = ft_gkrellm

COMPILER = clang++
WFLAG = -Wall -Werror -Wextra
HEADER = -I /includes

NCURSES_LINK = -lncurses

SRC_DIR = srcs
SRC =	main.cpp \
		IMonitorDisplay.class.cpp \
		IMonitorModule.class.cpp \
		AModule.class.cpp \
		NcursesDisplay.class.cpp \
		NameModule.class.cpp \
		OSModule.class.cpp \
		TimeModule.class.cpp \
		CpuUsageModule.class.cpp \
		CpuInfoModule.class.cpp \
		RamModule.class.cpp \
		NetworkModule.class.cpp
		
SRCS =	$(addprefix $(SRC_DIR)/, $(SRC))

all:
	$(COMPILER) $(WFLAG) $(NCURSES_LINK) $(HEADER) $(SRCS) -o $(NAME)

clean:
	

fclean: 
	rm -rf $(NAME)

re: fclean all
