SRC = pipex.c pipex_utils.c
SRC_BNS = 
OBJ = ${SRC:.c=.o}
OBJ_BNS = ${SRC_BNS:.c=.o}
NAME = pipex
NAME_BNS = pipex_bonus
CC = cc
RM = rm -f
FLAG = -Wall -Wextra -Werror

all: ${NAME}

mandatory/%.o: mandatory/%.c mandatory/pipex.h
	@${CC} ${FLAG} -c $< -o $@

bonus/%.o: bonus/%.c bonus/pipex_bonus.h
	@${CC} ${FLAG} -c $< -o $@

${NAME}: ${OBJ}
	@${CC} ${FLAG} $^ -o ${NAME}

bonus: ${OBJ_BNS}
	@${CC} ${FLAG} ${OBJ_BNS} -o ${NAME_BNS}

clean:
	@${RM} ${OBJ} ${OBJ_BNS}

fclean: clean
	@${RM} ${NAME} ${NAME_BNS}

re: fclean all