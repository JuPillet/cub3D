# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 13:15:25 by jpillet           #+#    #+#              #
#    Updated: 2021/06/14 19:44:54 by jpillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S	 		=	$(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	ALL			=	make -f Makefile_Darwin
	CLEAN		=	make clean -f Makefile_Darwin
	FCLEAN		=	make fclean -f Makefile_Darwin
	RE			=	make re -f Makefile_Darwin
else
	ALL			=	make -f Makefile_Linux
	CLEAN		=	make clean -f Makefile_Linux
	FCLEAN		=	make fclean -f Makefile_Linux
	RE			=	make re -f Makefile_Linux
endif

#.c.o			:
#					${MAKE}

all				:
					${ALL}

clean			:
					${CLEAN}

fclean			:
					${FCLEAN}

re				:
					${RE}

.PHONY			:	all clean fclean re
