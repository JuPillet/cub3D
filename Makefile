# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 13:15:25 by jpillet           #+#    #+#              #
#    Updated: 2021/05/12 12:16:41 by jpillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	cub3D

LIBFT			=	libft.a

MLX				=	libmlx.a

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
					cub_mallocers_area.c \
					cub_mallocers_game.c \
					cub_mallocers_level.c \
					cub_mallocers_screen.c)

SRCSPRSR		=	$(addprefix ./srcs/parsers/, \
					cub_parser.c \
					cub_parsers_map.c \
					cub_parsers_screen.c \
					cub_parsers_texture.c)

SRCSSTTR		=	$(addprefix ./srcs/setters/, \
					cub_setters_color.c \
					cub_setters_fonctions_hash_array.c \
					cub_setters_game.c \
					cub_setters_level.c \
					cub_setters_values.c)

SRCSGTTR		=	$(addprefix ./srcs/getters/, \
					cub_getter_setting.c \
					cub_getter_colors.c)

SRCSFLLR		=	$(addprefix ./srcs/freellers/, \
					cub_freellers_area.c \
					cub_freellers_game.c \
					cub_freellers_level.c \
					cub_freellers_screen.c)

##SRCSRNDR		=	$(addprefix ./srcs/render/, \
##						mini_ray.c \
##						mini_render.c \
##						mini_vector.c)

CC				=	gcc

rm				=	rm -rf

CFLAGS 			=	-Wall -Wextra -Werror

INCLUDES		=	./includes/

OBJSCMMN		=	${SRCSCMMN:.c=.o}

OBJSCHKR		=	${SRCSCHKR:.c=.o}

OBJSTEST		=	${SRCSTEST:.c=.o}

OBJSADDR		=	${SRCSADDR:.c=.o}

OBJSMLLC		=	${SRCSMLLC:.c=.o}

OBJSPRSR		=	${SRCSPRSR:.c=.o}

OBJSSTTR		=	${SRCSSTTR:.c=.o}

OBJSGTTR		=	${SRCSGTTR:.c=.o}

OBJSFLLR		=	${SRCSFLLR:.c=.o}

OBJSRNDR		=	${SRCSRNDR:.c=.o}

UNAME_S	 		=	$(shell uname -s)

FAGMLX			=	
ifeq ($(UNAME_S),Darwin)
	FLAGMLX		=	-lmlx -framework OpenGL -framework AppKit
else
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

$(NAME)			:	${LIBFT} ${MLX} ${OBJSCMMN} ${OBJSCHKR} ${OBJSADDR} ${OBJSMLLC} ${OBJSPRSR} ${OBJSSTTR} ${OBJSGTTR} ${OBJSFLLR} ${OBJSRNDR}
					$(CC) $(CFLAGS) $(OBJSCMMN) $(OBJSCHKR) $(OBJSADDR) $(OBJSMLLC) $(OBJSPRSR) $(OBJSSTTR) $(OBJSGTTR) $(OBJSFLLR) $(OBJSRNDR) ${LIBFT} ${MLX} $(FLAGMLX) -o ${NAME}

clean			:
					make clean -C ${DIRLIBFT}
					make clean -C ${DIRMLX}
					rm -rf	${OBJSCMMN} ${OBJSTEST} ${OBJSADDR} ${OBJSMLLC} ${OBJSCHKR} \
							${OBJSPRSR} ${OBJSSTTR} ${OBJSGTTR} ${OBJSFLLR} ${OBJSRNDR} 

fclean			:	clean
					make fclean -C ${DIRLIBFT}
					rm -rf	${NAME} ${NAMELIN} ${NAMEMPRSR} ${NAMELPRSR} ${INCLUDES}${HDLFT} ${INCLUDES}${HDMLX} \
							${LIBFT} ${DIRMLX}${MLX} ${MLX}

re				:	fclean all

.PHONY			:	all clean fclean re
