# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 13:15:25 by jpillet           #+#    #+#              #
#    Updated: 2021/04/17 15:36:06 by jpillet          ###   ########.fr        #
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

DIRMLX			=	./minilibx-linux/

SRCSCMMN		=	$(addprefix ./srcs/common/, \
						miniRT.c)

SRCSADDR		=	$(addprefix ./srcs/adders/, \
						mini_adders_2ds_primitives.c \
						mini_adders_3ds_primitives.c \
						mini_adders_informs.c)

SRCSMLLC		=	$(addprefix ./srcs/mallocers/, \
						mini_mallocers_2ds_primitives.c \
						mini_mallocers_3ds_primitives.c \
						mini_mallocers_ambients_scene.c \
						mini_mallocers_leaves.c \
						mini_mallocers_pov.c \
						mini_mallocers_rays.c \
						mini_mallocers_screen.c)

SRCSPRSR		=	$(addprefix ./srcs/parsers/, \
						mini_parser.c \
						mini_parsers_2ds_primitives.c \
						mini_parsers_3ds_primitives.c \
						mini_parsers_informs.c \
						mini_parsers_leaves.c)

SRCSSTTR		=	$(addprefix ./srcs/setters/, \
						mini_setters_2ds_promitives.c \
						mini_setters_3ds_primitives.c \
						mini_setters_color.c \
						mini_setters_fonctions_hash_array.c \
						mini_setters_screen.c \
						mini_setters_values.c)

SRCSGTTR		=	$(addprefix ./srcs/getters/, \
						mini_get_colors.c)

SRCSFLLR		=	$(addprefix ./srcs/freellers/, \
						mini_freellers_2ds_primitives.c \
						mini_freellers_3ds_primitives.c \
						mini_freellers_all_2ds_primitives.c \
						mini_freellers_all_3ds_primitives.c \
						mini_freellers_all_informs.c \
						mini_freellers_ambients_scene.c \
						mini_freellers_leaves.c \
						mini_freellers_pov.c \
						mini_freellers_rays.c \
						mini_freellers_screen.c)

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
					mv ${DIRMLX}${MLX} ./
					cp ${DIRMLX}${HDMLX} ${INCLUDES}

${LIBFT}		:
					make -C ${DIRLIBFT}
					mv ${DIRLIBFT}${LIBFT} ./
					cp ${DIRLIBFT}${HDLFT} ${INCLUDES}

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
