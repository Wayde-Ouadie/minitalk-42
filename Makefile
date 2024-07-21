# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 04:21:40 by Wayde             #+#    #+#              #
#    Updated: 2024/07/21 03:10:20 by oel-feng         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SERVER = mandatory/utils/ft_printf.c mandatory/client.c
SRC_CLIENT = mandatory/utils/ft_printf.c mandatory/server.c
	
SRC_BNS_SERVER = 
SRC_BNS_CLIENT =
	
OBJ_SERVER = ${SRC_SERVER:.c=.o}
OBJ_CLIENT = ${SRC_CLIENT:.c=.o}
SRC_BNS_SERVER = ${SRC_BNS_SERVER:.c=.o}
SRC_BNS_SERVER = ${SRC_BNS_SERVER:.c=.o}
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = CLIENT_BONUS
CC = cc
RM = rm -f
FLAG = -Wall -Wextra -Werror

all: ${SERVER} ${CLIENT}

mandatory/%.o: mandatory/%.c mandatory/minitalk.h
	@${CC} ${FLAG} -c $< -o $@

bonus/%.o: bonus/%.c bonus/mintalk_bonus.h
	@${CC} ${FLAG} -c $< -o $@

${SERVER}: ${OBJ_SERVER}
	@${CC} ${FLAG} $^ -o ${SERVER}
	
${CLIENT}: ${OBJ_CLIENT}
	@${CC} ${FLAG} $^ -o ${CLIENT}

bonus: ${SERVER_BONUS} ${CLIENT_BONUS}
	
${SERVER_BONUS}: ${OBJ_BNS_SERVER}	
	@${CC} ${FLAG} ${OBJ_BNS} -o ${SERVER_BONUS}
	
${CLIENT_BONUS}: ${OBJ_BNS_SERVER}	
	@${CC} ${FLAG} ${OBJ_BNS} -o ${CLIENT_BONUS}

clean:
	@${RM} ${OBJ_SERVER} ${OBJ_SERVER} ${OBJ_BNS_SERVER} ${OBJ_BNS_CLIENT}

fclean: clean
	@${RM} ${SERVER} ${CLIENT} ${SERVER_BONUS} ${CLIENT_BONUS}

re: fclean all