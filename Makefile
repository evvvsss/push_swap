NAME		= 	push_swap

SRCS		=  	push_swap.c \
				ft_lstnew.c \
				ft_lstadd_back.c \
				ft_lstlast.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				sort.c \
				commands.c \
				operations.c \
				operations_2.c \
				big_to_a.c \
				ft_atoi.c 		\

LIBFT		=	libft/

#BONUS_SRCS	= 	ft_split.c 		\

INCLUDES	=	./

OBJS		= 	${SRCS:.c=.o}

BONUS_OBJS	= 	${BONUS_SRCS:.c=.o}

CC			= 	gcc -g
RM			= 	rm -f

ARG			=	`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

CFLAGS		= 	-Wall -Werror -Wextra 

.c.o:
				${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS}
				@make -C ${LIBFT}
				gcc -o $(NAME) $(OBJS) $(LIBFT)/libft.a

${LIBFT}:		make -C $(LIBFT)

all:			$(LIBFT) ${NAME}

bonus:			${BONUS_OBJS}
				gcc -o ${NAME} $(BONUS_OBJS)

clean:			
				${RM} ${OBJS} $(BONUS_OBJS)
				make clean -C $(LIBFT) fclean


fclean:			clean 
				rm -rf ${NAME}
				make clean -C ${LIBFT} fclean


re:				fclean all

.PHONY:			all clean fclean re