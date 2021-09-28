#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_info
{
	int				value;
	int				index;
	int				flag;
	struct s_info	*next;
}				t_info;

typedef struct s_elem
{
	int			middle;
	int			min;
	int			max;
	int			flag;
	int			argc;
	int			counter;
}				t_elem;

void	print(t_info *a, char n); //delete
t_info	*ft_lstnew(int value);
int		*add_array( t_info *a, t_elem *el);
int		check_args(char *argv, t_info **a, t_elem **el);
t_info	*ft_lstlast(t_info *lst);
void	ft_lstadd_back(t_info **lst, t_info *new);
void	ft_lstadd_front(t_info **lst, t_info *new);
void	ft_lstclear(t_info **lst);
void	sort(int **array, int start, int end);
void	elem_init_1(t_elem **el, int *array);
void	elem_init_0(t_elem **el);
void	pa_pb(t_info **first, t_info **second, char name, t_elem **el);
void	rrr(t_info **a, t_info **b, t_elem **el);
void	rra_rrb(t_info **a, char name, t_elem **el);
void	ra_rb(t_info **a, char name, t_elem **el);
void	rr(t_info **a, t_info **b, t_elem **el);
void	sa_sb(t_info **a, char name, t_elem **el);
void	ss(t_info **a, t_info **b, t_elem **el);
void	small_to_b(t_info **a, t_info **b, t_elem **el, int argc);
void	big_to_a(t_info **a, t_info **b, t_elem **el, int *array);
void	elem_init_2(t_elem **el, t_info *a, int *array);
void	next_elem(int *array, t_elem **el, t_info **a);
void	move_to_b(t_info **a, t_info **b, t_elem **el, int *array);

#endif