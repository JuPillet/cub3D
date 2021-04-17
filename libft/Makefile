# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 19:18:43 by jpillet           #+#    #+#              #
#    Updated: 2021/04/16 14:35:01 by jpillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libft.a

CC			=	gcc

ARRC		=	ar rcs

CFLAGS 		=	-Wall -Wextra -Werror

SRCS	 	=	ft_atof.c \
				ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_error.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_issigned.c \
				ft_isspace.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_split.c \
				ft_itoa.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strmapi.c \
				ft_substr.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				get_next_line.c \
				ft_mallocers_types.c \
				ft_freellers_types.c \

INCLUDES 	=	-I .

OBJS 		=	${SRCS:.c=.o}

.c.o		:
				${CC} ${INCLUDES} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME)		:	${OBJS}
				${ARRC} ${NAME} ${OBJS}

all			:	${NAME}

clean		:
				rm -f ${OBJS}

fclean		:	clean
				rm -f ${NAME}

re			:	fclean all

.PHONY		:	all clean fclean re