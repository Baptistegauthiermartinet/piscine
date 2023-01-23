SRCS	= srcs/*.c
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
NAME	= rush-02

all:		${NAME}

${NAME}:
			${CC} ${CFLAGS} -o ${NAME} ${SRCS}

fclean:
			${RM} ${NAME}

.PHONY:		all fclean ${NAME}