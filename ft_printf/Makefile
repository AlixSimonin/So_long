NAME = libftprintf.a
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m
MAGENTA = \033[0;95m

SRCS = ft_printf.c \
		ft_print_percent.c \
		ft_print_char.c \
		ft_print_hexa.c \
		ft_print_nbr.c \
		ft_print_void.c \
		ft_print_str.c \
		ft_print_unsigned.c \
		utils/printf_itoa.c \
		utils/printf_putstr.c \
		utils/printf_strlen.c \

all: ${NAME}

${NAME}: ${OBJS}
	@$(AR) ${NAME} ${OBJS}
.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re 
