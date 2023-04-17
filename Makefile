NAME			=	so_long

PRINTF			=	ft_printf/libftprintf.a

SRCS			=	srcs/check_arg.c \
					srcs/game.c \
					srcs/main.c \
					utils/ft_memset.c \
					utils/ft_strlen.c \
					utils/ft_strnstr.c \


OBJS			=	${SRCS:.c=.o}


MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I includes

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra

all				:	${NAME}

$(NAME): $(OBJS) ${OBJS_GNL}
	@make -C ft_printf
	cc $(OBJS) ${OBJS_GNL} minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a -L. -lXext -L. -lX11 ${PRINTF} -o $(NAME)
	@make clean

clean			:
					make clean -C ft_printf
					rm -rf ${OBJS}

fclean			:	clean
					make fclean -C ft_printf
					rm -rf ${PRINTF}
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re bonus
