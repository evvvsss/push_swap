#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <limits.h>
# define MAX 21474836417

typedef struct s_info
{
	int				value;
	int				index;
	struct s_info	*next;
}				t_info;

typedef struct s_elem
{
	int			argc;
	int			add;
	int			cnt;
}				t_elem;

t_info		*ft_lstnew(int value);
t_info		*ft_lstlast(t_info *lst);
int			ft_atoi(const char *str, t_elem	**el);
int			check_repeats(t_info *a, int digit);
int			*add_array( t_info *a, t_elem *el);
int			check_args(char *argv, t_info **a, t_elem **el);
void		ft_lstadd_back(t_info **lst, t_info *new);
void		ft_lstadd_front(t_info **lst, t_info *new);
void		ft_lstclear(t_info **lst);
void		sort_array(int **array, int start, int end);
void		elem_init_0(t_info **a, t_info **b, t_elem **el, int argc);
void		print(t_info *a, char n);
void		pa_pb(t_info **first, t_info **second, char name, t_elem **el);
void		rrr(t_info **a, t_info **b, t_elem **el);
void		rra_rrb(t_info **a, char name, t_elem **el);
void		ra_rb(t_info **a, char name, t_elem **el);
void		rr(t_info **a, t_info **b, t_elem **el);
void		sa_sb(t_info **a, char name, t_elem **el);
void		ss(t_info **a, t_info **b, t_elem **el);
void		next_elem(int *array, t_elem **el, t_info **a);
void		index_to_lists(int *array, t_info **a);
void		sort_a(t_info **a, t_info **b, t_elem **el);
void		sort_b(t_info **a, t_info **b, t_elem **el, int max);
int			sorting_check(t_info *a, int *array);
int			find_elem(int index, t_info *a);
int			ft_lstsize(t_info *lst);
int			max_index(t_info *a);
void		sort_2(t_info **a, t_elem **el);
void		sort_3(t_info **a, t_elem **el);
void		sort_4(t_info **a, t_info **b, t_elem **el);
void		sort_5(t_info **a, t_info **b, t_elem **el);
int			check_string(char *argv, int space);
int			str_with_spaces(char *argv, t_info **a, t_elem **el);
void		main_part(int **array, t_info **a, t_info **b, t_elem **el);
void		ft_clear(t_info **a, t_elem **el);

#endif