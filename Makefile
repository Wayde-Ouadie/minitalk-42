# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-feng <oel-feng@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 15:35:59 by oel-feng          #+#    #+#              #
#    Updated: 2024/07/26 07:05:48 by oel-feng         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SERVER = mandatory/utils/ft_fprintf.c mandatory/utils/utils.c mandatory/server.c
SRC_CLIENT = mandatory/utils/ft_fprintf.c mandatory/utils/utils.c mandatory/client.c

SRC_BNS_SERVER = bonus/utils/ft_fprintf_bonus.c bonus/utils/utils_bonus.c bonus/server_bonus.c
SRC_BNS_CLIENT = bonus/utils/ft_fprintf_bonus.c bonus/utils/utils_bonus.c bonus/client_bonus.c

OBJ_SERVER = ${SRC_SERVER:.c=.o}
OBJ_CLIENT = ${SRC_CLIENT:.c=.o}
OBJ_BNS_SERVER = ${SRC_BNS_SERVER:.c=.o}
OBJ_BNS_CLIENT = ${SRC_BNS_CLIENT:.c=.o}

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
CC = cc
RM = rm -f
FLAG = -Wall -Wextra -Werror

all: ${SERVER} ${CLIENT}

mandatory/%.o: mandatory/%.c mandatory/minitalk.h
	@${CC} ${FLAG} -c $< -o $@

${SERVER}: ${OBJ_SERVER}
	@${CC} ${FLAG} $^ -o ${SERVER}

${CLIENT}: ${OBJ_CLIENT}
	@${CC} ${FLAG} $^ -o ${CLIENT}

bonus: ${SERVER_BONUS} ${CLIENT_BONUS}

bonus/%.o: bonus/%.c bonus/minitalk_bonus.h
	@${CC} ${FLAG} -c $< -o $@

${SERVER_BONUS}: ${OBJ_BNS_SERVER}	
	@${CC} ${FLAG} $^ -o ${SERVER_BONUS}

${CLIENT_BONUS}: ${OBJ_BNS_CLIENT}	
	@${CC} ${FLAG} $^ -o ${CLIENT_BONUS}

clean:
	@${RM} ${OBJ_SERVER} ${OBJ_CLIENT} ${OBJ_BNS_SERVER} ${OBJ_BNS_CLIENT}

fclean: clean
	@${RM} ${SERVER} ${CLIENT} ${SERVER_BONUS} ${CLIENT_BONUS}

re: fclean all