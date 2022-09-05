# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 18:24:22 by fnochiza          #+#    #+#              #
#    Updated: 2022/09/04 21:11:33 by fnochiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = minishell

LIBFTNAME = libft.a

CFLAGS = #-Werror -Wall -Wextra

OBJS := $(*.o)

SRC =	minishell.c \
		minishell_utils.c \
		minishell_parsing_1.c

HDR =	minishell.h

LIBFTPATH = ./libft/

RDLN		= -lreadline -L ~/.brew/Cellar/readline/8.1.2/lib \
			  -I~/.brew/Cellar/readline/8.1.2/include

all: e

${NAME}: $(OBJS) $(HDR) Makefile
	make -C ${LIBFTPATH}
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${CC} ${CFLAGS} -g ${SRC} ${LIBFTNAME} $(RDLN) -o ${NAME} -lreadline -L \
	~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include

clean:
	rm -rf *.o
	rm -rf ./libft/*.o
	rm -rf ./libft/gnl_other/*.o
	rm -rf ./libft/ft_printf/*.o
	rm -rf ./libft/ft_printf/sources/*.o

fclean: clean
	rm -f $(LIBFTNAME) ${OBJS} $(NAME)

re: fclean ${NAME}

e:	clean
	${CC} ${CFLAGS} -g ${SRC} ${LIBFTNAME} $(RDLN) -o ${NAME} -lreadline -L \
	~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include
