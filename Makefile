all :
	cc -Wall -Wextra -Werror pipex.c pipex_utils.c -o pipex
fclean :
	rm -rf pipex