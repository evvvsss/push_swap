NAME		= 	push_swap

BONUS_NAME	= 	checker

SRCS		=  	push_swap.c			\
				ft_lstnew.c			\
				ft_lstadd_back.c	\
				ft_lstlast.c		\
				ft_lstadd_front.c	\
				ft_lstclear.c		\
				sort_array.c		\
				commands.c			\
				operations.c		\
				operations_2.c		\
				ft_atoi.c			\
				ft_lstsize.c		\
				sort_100.c			\
				sort_2345.c			\
				print_stack.c		\
				check_args.c		\
				main_part.c			\

LIBFT		=	libft/

BONUS_SRCS	= 	bonus_commands.c 	\
				bonus_oper.c		\
				push_swap_bonus.c 	\
				get_next_line.c \
				get_next_line_utils.c \
				ft_lstnew.c			\
				ft_lstadd_back.c	\
				ft_lstlast.c		\
				ft_lstadd_front.c	\
				ft_lstclear.c		\
				sort_array.c		\
				commands.c			\
				operations.c		\
				operations_2.c		\
				ft_atoi.c			\
				ft_lstsize.c		\
				sort_100.c			\
				sort_2345.c			\
				print_stack.c		\
				check_args.c		\
				main_part.c			\


INCLUDES	=	./

OBJS		= 	${SRCS:.c=.o}

BONUS_OBJS	=  	${BONUS_SRCS:.c=.o}

CC			= 	gcc -g
RM			= 	rm -f

CFLAGS		= 	-Wall -Werror -Wextra 

.c.o:
				${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS}
				@make -C $(LIBFT)
				gcc -o $(NAME) $(OBJS) $(LIBFT)/libft.a
				
${BONUS_NAME}:	${BONUS_OBJS}
				@make -C $(LIBFT)
				gcc -o $(BONUS_NAME) ${BONUS_OBJS} $(LIBFT)/libft.a

${LIBFT}:		make -C $(LIBFT)

all:			$(LIBFT) ${NAME} 

bonus:			${BONUS_NAME}

clean:			
				${RM} ${OBJS} $(BONUS_OBJS)
				make clean -C $(LIBFT) fclean


fclean:			clean 
				rm -rf ${NAME} ${BONUS_NAME}
				make clean -C ${LIBFT} fclean


re:				fclean all

.PHONY:			all clean fclean re