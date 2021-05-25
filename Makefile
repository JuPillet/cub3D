# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 13:15:25 by jpillet           #+#    #+#              #
#    Updated: 2021/05/25 15:14:53 by jpillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S	 		=	$(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	ALL		=	make -f makefile_darwin
	CLEAN		=	make clean -f makefile_darwin
	FCLEAN		=	make fclean -f makefile_darwin
	RE			=	make re -f makefile_darwin
else
	MAKE		=	make -f makefile_linux
	CLEAN		=	make clean -f makefile_linux
	FCLEAN		=	make fclean -f makefile_linux
	RE			=	make re -f makefile_linux
endif

.c.o			:
					${MAKE}

all				:
					${ALL}

clean			:
					${CLEAN}

fclean			:
					${FCLEAN}

re				:
					${RE}

.PHONY			:	all clean fclean re
