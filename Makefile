SRCS = $(addprefix src/, main.c rotate.c swap.c trie.c utils.c utils2.c push.c copytab.c action.c mediane.c \
			find_index.c algo5_3.c steps.c)

SRCS_BONUS = $(addprefix src_bonus/, main.c rotate.c swap.c trie.c utils.c utils2.c push.c copytab.c action.c mediane.c \
			find_index.c algo5_3.c steps.c checker.c)

NAME = push_swap

NAME_BONUS = push_swap_bonus


INC = -I ./

FLAGS = -g3 

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

LIBFT = libft.a

${NAME} : ${OBJS} ${LIBFT}
			make -C libft/ all
			mv libft/libft.a ./
			gcc ${FLAGS} ${INC} $(OBJS) -o $(NAME) libft.a

${LIBFT}:
	make -C libft/ all
	mv libft/libft.a ./

all : ${NAME}

%.o:%.c
		gcc ${FLAGS} -c $< -o $@

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS} ${LIBFT}
		gcc ${FLAGS} ${INC} ${OBJS_BONUS} -o ${NAME_BONUS} ${LIBFT}
clean :
		make -C ./libft/ clean
		rm -rf ${OBJS} ${OBJS_BONUS}

fclean : clean
		rm -rf ${NAME} ${NAME_BONUS}
		make -C ./libft/ fclean

re : fclean all

.PHONY : all bonus clean fclean re bonus libft