# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 13:15:25 by jpillet           #+#    #+#              #
#    Updated: 2021/04/28 13:33:37 by jpillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	miniRT

NAMELIN			=	miniRTlin

NAMEMPRSR		=	miniParseTestM

NAMELPRSR		=	miniParseTestL

LIBFT			=	libft.a

MLX				=	libmlx.a

HDLFT			=	libft.h

HDMLX			=	mlx.h

DIRLIBFT		=	./libft/

DIRMLX			=	./minilibx_opengl/

SRCSCMMN		=	$(addprefix ./srcs/common/, \
						cub3d.c)

SRCSCHCK		=	$(addprefix ./srcs/checkers, \
					cub_checkers_map.c \
					cub_checkers_map_validity.c \
					cub_checkers_player.c)

SRCSMLLC		=	$(addprefix ./srcs/mallocers/, \
					cub_mallocers_area.c \
					cub_mallocers_game.c \
					cub_mallocers_level.c \
					cub_mallocers_screen.c)

SRCSPRSR		=	$(addprefix ./srcs/parsers/, \
					cub_parser.c \
					cub_parser_map.c \
					cub_parsers_screen.c \
					cub_parser_texture.c)

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

OBJSTEST		=	${SRCSTEST:.c=.o}

OBJSADDR		=	${SRCSADDR:.c=.o}

OBJSMLLC		=	${SRCSMLLC:.c=.o}

OBJSPRSR		=	${SRCSPRSR:.c=.o}

OBJSSTTR		=	${SRCSSTTR:.c=.o}

OBJSGTTR		=	${SRCSGTTR:.c=.o}

OBJSFLLR		=	${SRCSFLLR:.c=.o}

OBJSRNDR		=	${SRCSRNDR:.c=.o}

LIBMAC			=	-lmlx -framework OpenGL -framework AppKit

LIBLIN			=	-lX11 -lXext -lm -lpthread

.c.o			:
					cp ${DIRLIBFT}${HDLFT} ${INCLUDES}
					${CC} -I${INCLUDES} -c $< -o ${<:.c=.o}
##					${CC} ${CFLAGS} -I${INCLUDES} -c $< -o ${<:.c=.o}

$(MLX)		:
					make -C ${DIRMLX}

${LIBFT}		:
					make -C ${DIRLIBFT}

$(NAME) 		:	${OBJSCMMN} ${OBJSADDR} ${OBJSMLLC} ${OBJSPRSR} ${OBJSSTTR} ${OBJSGTTR} ${OBJSFLLR} ${OBJSRNDR} ${LIBFT}
					$(CC) $(CFLAGS) $(OBJSCMMN) $(OBJSADDR) $(OBJSMLLC) $(OBJSPRSR) $(OBJSSTTR) $(OBJSGTTR) $(OBJSFLLR) $(OBJSRNDR) ${LIBFT} $(LIBMAC) -o ${NAMELIN}

$(NAMELIN)		:	${MLX} ${OBJSCMMN} ${OBJSADDR} ${OBJSMLLC} ${OBJSPRSR} ${OBJSSTTR} ${OBJSGTTR} ${OBJSFLLR} ${LIBFT}
					$(CC) $(CFLAGS) $(OBJSCMMN) $(OBJSADDR) $(OBJSMLLC) $(OBJSPRSR) $(OBJSSTTR) $(OBJSGTTR) $(OBJSFLLR) $(OBJSRNDR) ${LIBFT} ${MLX} $(LIBLIN) -o ${NAMELIN}

all				:	${NAME}

alll			:	${NAMELIN}

allmt			:	$(NAMEMPRSR)

alllt			:	$(NAMELPRSR)

clean			:
					make clean -C ${DIRLIBFT}
					make clean -C ${DIRMLX}
					rm -rf	${OBJSCMMN} ${OBJSTEST} ${OBJSADDR} ${OBJSMLLC} \
							${OBJSPRSR} ${OBJSSTTR} ${OBJSGTTR} ${OBJSFLLR} ${OBJSRNDR} 

fclean			:	clean
					make fclean -C ${DIRLIBFT}
					rm -rf	${NAME} ${NAMELIN} ${NAMEMPRSR} ${NAMELPRSR} ${INCLUDES}${HDLFT} ${INCLUDES}${HDMLX} \
							${LIBFT} ${DIRMLX}${MLX} ${MLX}

re				:	fclean all

rel				:	fclean alll

.PHONY			:	all alll allmt alllt clean fclean re rel
