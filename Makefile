NAME			=	so_long

PRINTF			=	ft_printf/libftprintf.a

LIBFT			=	libft/libft.a

GNL				=	get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c \

SRCS			=	srcs/check_arg.c \
					srcs/main.c \
					srcs/parsing.c \
					srcs/free_all.c \

OBJS			=	${SRCS:.c=.o}

OBJS_GNL		=	${GNL:.c=.o}

MLX_FLAGS		=	minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a -L. -lXext -L. -lX11 met ca dans le compilateur connasse

HEAD			=	-I includes

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m
MAGENTA = \033[0;95m

all				:	${NAME}

$(NAME): $(OBJS) ${OBJS_GNL}
	@make -C libft
	@make -C ft_printf
	cc $(OBJS) ${OBJS_GNL} ${LIBFT} ${PRINTF} -o $(NAME)
	@make clean
	@echo "$(GREEN)so_long executable files created!$(DEF_COLOR)"

clean			:
					@make clean -C libft
					@make clean -C ft_printf
					@rm -rf ${OBJS} ${OBJS_GNL}
					@echo "$(BLUE)so_long object files cleaned!$(DEF_COLOR)"

fclean			:	clean
					@make fclean -C libft
					@make fclean -C ft_printf
					@rm -rf ${LIBFT}
					@rm -rf ${PRINTF}
					@rm -rf ${NAME}
					@echo "$(MAGENTA)so_long executable files cleaned!$(DEF_COLOR)"

re				:	fclean all

.PHONY			:	all clean fclean re bonus
