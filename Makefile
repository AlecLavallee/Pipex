# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 11:56:39 by alelaval          #+#    #+#              #
#    Updated: 2021/11/29 14:36:39 by alelaval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = ./srcs/parser/parser.c \
		./srcs/error/error.c \
		./srcs/error/free.c \
		./srcs/pipex.c \

OBJS =	${SRCS:.c=.o}

INCLUDE =	./headers/
LIB_PATH =	./libft/
CFLAGS =	-Wall -Wextra -Werror
RM = 		rm -rf

all: 		${NAME}

bonus:		pipex_bonus

lib:
	make -C libft

.c.o:
			${CC} ${CFLAGS} -I${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} $(LIB)
			${CC} ${CFLAGS} -I${INCLUDE} -o ${NAME} ${OBJS} -L./libft/ -lft

${NAME_BONUS}:	${OBJS} $(LIB)
					${CC} ${CFLAGS} -I${INCLUDE} -o ${NAME_BONUS} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:	clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		lib bonus all clean fclean re