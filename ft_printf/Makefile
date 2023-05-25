SOURCEFILES	=	ft_printf.c			\
				puthexa.c			\
				ft_itoa_unsigned.c

OBJECTS		= ${SOURCEFILES:.c=.o}
NAME		= libftprintf.a
COMPILER	= cc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re, test

all: ${NAME}


${NAME} : ${OBJECTS}
	@echo ${SOURCEFILES}
	@make -C Libft
	@cp Libft/libft.a .
	@mv libft.a $(NAME)
	ar -crs $@ $^

%.o : %.c
	${COMPILER} ${FLAGS} -c $< -o $@

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

test:
	${COMPILER} ${FLAGS} ft_printf.c ft_printf.h puthexa.c Libft/ft_strdup.c Libft/ft_strlen.c Libft/ft_memcpy.c Libft/ft_itoa.c ft_itoa_unsigned.c