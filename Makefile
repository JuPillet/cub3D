# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 13:15:25 by jpillet           #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2021/06/15 13:32:17 by jpillet          ###   ########.fr        #
=======
#    Updated: 2021/05/25 20:11:11 by jpillet          ###   ########.fr        #
>>>>>>> parent of ee737d3... JuPillet My 42 cub3D
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

<<<<<<< HEAD
=======
.c.o			:
					${MAKE}

>>>>>>> parent of ee737d3... JuPillet My 42 cub3D
all				:
					${ALL}

clean			:
					${CLEAN}

fclean			:
					${FCLEAN}

re				:
					${RE}

.PHONY			:	all clean fclean re
