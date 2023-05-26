COMPILER	= cc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror

test:
	${CC} ${FLAGS} ops.c call_ops.c algorithm.c push_swap.c sort_main_utils.c ft_printf/*.c ft_printf/Libft/*.c