# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 13:15:25 by jpillet           #+#    #+#              #
#    Updated: 2021/05/14 17:24:39 by jpillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	cub3D

LIBFT			=	libft.a

HDLFT			=	libft.h

HDMLX			=	mlx.h

DIRLIBFT		=	./libft/

DIRMLX			=	./minilibx-linux/

SRCSCMMN		=	$(addprefix ./srcs/common/, \
						cub3d.c)

SRCSCHKR		=	$(addprefix ./srcs/checkers/, \
					cub_checkers_map.c \
					cub_checkers_map_validity.c)

SRCSMLLC		=	$(addprefix ./srcs/mallocers/, \
					cub_mallocers_area.c)

SRCSPRSR		=	$(addprefix ./srcs/parsers/, \
					cub_parser.c \
					cub_parsers_map.c \
					cub_parsers_screen.c \
					cub_parsers_texture.c)

SRCSRNDR		=	$(addprefix ./srcs/renders/, \
					cub_renders.c)
					
SRCSSTTR		=	$(addprefix ./srcs/setters/, \
					cub_setters_color.c \
					cub_setters_game.c \
					cub_setters_level.c \
					cub_setters_mlx.c \
					cub_setters_values.c)

SRCSGTTR		=	$(addprefix ./srcs/getters/, \
					cub_getters_color.c \
					cub_getters_line.c)

SRCSFLLR		=	$(addprefix ./srcs/freellers/, \
					cub_freellers_modules.c \
					cub_freellers_game.c)

SRCSCOIN		=	$(addprefix ./srcs/coin/, \
						cub_key_push.c \
						cub_coin.c)

CC				=	gcc

rm				=	rm -rf

CFLAGS 			=	-Wall -Wextra -Werror

INCLUDES		=	./includes/

OBJSCMMN		=	${SRCSCMMN:.c=.o}

OBJSCHKR		=	${SRCSCHKR:.c=.o}

OBJSMLLC		=	${SRCSMLLC:.c=.o}

OBJSPRSR		=	${SRCSPRSR:.c=.o}

OBJSRNDR		=	${SRCSRNDR:.c=.o}

OBJSSTTR		=	${SRCSSTTR:.c=.o}

OBJSGTTR		=	${SRCSGTTR:.c=.o}

OBJSFLLR		=	${SRCSFLLR:.c=.o}

OBJSCOIN		=	${SRCSCOIN:.c=.o}

UNAME_S	 		=	$(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	MLX			=	libmlx.a
	FLAGMLX		=	-lmlx -framework OpenGL -framework AppKit

else
	MLX			=	libmlx_Linux.a
	FLAGMLX		=	-lX11 -lXext -lm -lpthread
endif

.c.o			:
					cp ${DIRLIBFT}${HDLFT} ${INCLUDES}
					${CC} -I${INCLUDES} -c -g $< -o ${<:.c=.o}
##					${CC} ${CFLAGS} -I${INCLUDES} -c $< -o ${<:.c=.o}

all				:	${NAME}

$(MLX)			:
					make -C ${DIRMLX}
					mv ${DIRMLX}${MLX} ./
					cp ${DIRMLX}${HDMLX} ${INCLUDES}

${LIBFT}		:
					make -C ${DIRLIBFT}
					mv ${DIRLIBFT}${LIBFT} ./
					cp ${DIRLIBFT}${HDLFT} ${INCLUDES}

$(NAME)			:	${LIBFT} ${MLX} ${OBJSCMMN} ${OBJSCHKR} ${OBJSMLLC} ${OBJSPRSR} ${OBJSSTTR} ${OBJSGTTR} ${OBJSFLLR} ${OBJSCOIN} ${OBJSRNDR}
					${CC} ${CFLAGS} ${OBJSCMMN} ${OBJSCHKR} ${OBJSMLLC} ${OBJSPRSR} ${OBJSSTTR} ${OBJSGTTR} ${OBJSFLLR} ${OBJSCOIN} ${OBJSRNDR} ${LIBFT} ${MLX} $(FLAGMLX) -o ${NAME}

clean			:
					make clean -C ${DIRLIBFT}
					make clean -C ${DIRMLX}
					rm -rf	${OBJSCMMN} ${OBJSTEST} ${OBJSMLLC} ${OBJSCHKR} \
							${OBJSPRSR} ${OBJSSTTR} ${OBJSGTTR} ${OBJSFLLR} ${OBJSCOIN}

fclean			:	clean
					make fclean -C ${DIRLIBFT}
					rm -rf	${NAME} ${NAMELIN} ${NAMEMPRSR} ${NAMELPRSR} ${INCLUDES}${HDLFT} ${INCLUDES}${HDMLX} \
							${LIBFT} ${DIRMLX}${MLX} ${MLX}

re				:	fclean all

.PHONY			:	all clean fclean re
