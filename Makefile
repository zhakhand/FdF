SRCS = srcs/closing.c srcs/draw.c fdf.c srcs/frees.c srcs/read.c \
srcs/utils.c srcs/hex_utils.c srcs/events.c srcs/draw_t_d.c

HEAD = ./include/fdf.h 

NAME = fdf

CC = cc

RM = rm -f

OBJS = ${SRCS:%.c=%.o}

CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

%.o:	%.c
		@echo "Compiling $<..."
		${CC} ${CFLAGS} -Ilibft -c $? -o $@

${NAME}:	fdf

fdf:	fdf.o
		${MAKE} -s -C libft
		${CC} ${CFLAGS} ${SRCS} -g ./libft/libft.a -o fdf -lmlx -lX11 -lXext -lm

bonus:	all #Because bonus is implemented in the main program

libft:
		make -C libft

clean:
		make clean -s -C libft
		${RM} ${OBJS}

fclean: clean
		${RM} fdf

re:		fclean all

.PHONY:	all clean fclean re bonus