# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 20:23:03 by iksaiz-m          #+#    #+#              #
#    Updated: 2024/09/10 20:26:45 by iksaiz-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC						= cc
NAME 					= minitalk
NAME_CLIENT				= client
NAME_SERVER				= server
CFLAGS					= -Wall -Wextra -Werror
LDFLAGS					= -L./libft -lft
SRC_CLIENT 				= client.c
SRC_SERVER 				= server.c

${NAME}: all

all:
	make -C ./libft
	make ${NAME_CLIENT}
	make ${NAME_SERVER}

${NAME_CLIENT}: ${SRC_CLIENT}
	@${CC} ${CFLAGS} ${SRC_CLIENT} -o ${NAME_CLIENT} ${LDFLAGS}

${NAME_SERVER}: ${SRC_SERVER}
	@${CC} ${CFLAGS} ${SRC_SERVER} -o ${NAME_SERVER} ${LDFLAGS}

clean:
	rm -rf *.o
	rm -rf tags
	make -C libft clean

fclean: 
	make clean
	rm -rf ${NAME_SERVER} ${NAME_CLIENT}
	make -C libft fclean

re:
	make fclean 
	make all

.PHONY: all clean fclean re