#include "push_swap.h"

void pa_pb(t_info **first, t_info **second, char name, t_elem  **el)
{
	t_info *tmp;

	
	if (!*second)
		return;
	if (!*first)
	{
		*first = ft_lstnew((*second)->value);
		(*first)->flag = (*second)->flag;
		(*first)->index = (*second)->index;
		tmp = *second;
		*second = (*second)->next;
		free(tmp);
	}
	else
	{
		ft_lstadd_front(first, ft_lst_copy(*second));
		tmp = *second;
		*second = (*second)->next;
		free(tmp);
	}
	if (name == 'a')
		write(1, "pa\n", 3);
	else if (name == 'b')
		write(1, "pb\n", 3);
	(*el)->counter++;
}

void rrr(t_info **a, t_info **b, t_elem  **el)
{
	rra_rrb(a, 'a', el);
	rra_rrb(b, 'b', el);
	write(1, "rrr\n", 4);
	(*el)->counter++;
}

void	rra_rrb(t_info **a, char name, t_elem  **el)
{
	t_info *tmp;
	t_info *tmp2;

	tmp = *a;
	while (tmp->next && tmp->next->next != NULL)
		tmp = tmp->next;
	tmp2 = tmp;
	tmp = tmp->next;
	tmp = ft_lst_copy(tmp);
	ft_lstadd_front(a, tmp);
	tmp2->next = NULL;
	if (name == 'a')
		write(1, "rra\n", 4);
	else if (name == 'b')
		write(1, "rrb\n", 4);
	(*el)->counter++;
}

void ra_rb(t_info **a, char name, t_elem  **el)
{
	t_info *tmp;

	tmp = ft_lst_copy(*a);
	ft_lstadd_back(a, tmp);
	tmp = *a;
	*a = (*a)->next;
	free(tmp);
	if (name == 'a')
		write(1, "ra\n", 3);
	else if (name == 'b')
		write(1, "rb\n", 3);
	(*el)->counter++;
}

void rr(t_info **a, t_info **b, t_elem  **el)
{
	ra_rb(a, 'a', el);
	ra_rb(b, 'b', el);
	write(1, "rr\n", 3);
	(*el)->counter++;
}

void sa_sb(t_info **a, char name, t_elem  **el)
{
	t_info *c;

	if ((*a) != NULL && (*a)->next != NULL)
	{
		c = ft_lstnew(0);
		c = (*a)->next;
		(*a)->next = (*a)->next->next;
		c->next = (*a);
		(*a) = c;
	}
	if (name == 'a')
		write(1, "sa\n", 3);
	else if (name == 'b')
		write(1, "sb\n", 3);
	(*el)->counter++;
}

void ss(t_info **a, t_info **b, t_elem  **el)
{
	sa_sb(a, 'c', el);
	sa_sb(b, 'c', el);
	write(1, "ss\n", 3);
	(*el)->counter++;
}
 
void elem_init_1(t_elem  **el, int *array, int argc)
{
	(*el) = (t_elem *)malloc(sizeof(t_elem));
	(*el)->argc = argc;
	(*el)->counter = 0;
	(*el)->min = array[0];
	printf("%d min \n", (*el)->min);
	(*el)->flag = 1;
	(*el)->max = array[argc];
	(*el)->middle = array[argc / 2];
	printf("%d max \n", (*el)->max);
	printf("%d mid \n", (*el)->middle);
}

void elem_init_2(t_elem  **el, t_info *a, int *array)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = 0;
	max = 0;
	if (!a)
		return ;
	else if (a->next == NULL)
	{
		(*el)->middle = (*el)->max;
		return ;
	}
	(*el)->argc = (*el)->argc / 2;
	while (array[i] != '\0')
	{
		if ((*el)->min == array[i])
			min = i + 1;
		if ((*el)->max == array[i])
			max = i;
		i++;
	}
	//(*el)->min = array[min];
	(*el)->middle = array[(max - min) / 2 + min];
	printf("%d max \n", (*el)->max);
	printf("%d mid \n", (*el)->middle);
	printf("%d min \n", (*el)->min);
	(*el)->flag++;
}

void	small_to_b(t_info **a, t_info **b, t_elem  **el, int argc)
{
	int	i;

	i = 0;
	while ((*a) && i <= argc)
	{	
		if ((*a)->value <= (*el)->middle)
			pa_pb(b, a, 'b', el);
		else
			ra_rb(a, 'a', el);
		i++;
	}
}

void	next_elem(int *array, t_elem  **el, t_info **a)
{
	int i;

	i = 0;
	while (array[i] != '\0' && (*el)->min != array[i])
		i++;
	(*a)->index = i;
	(*el)->min = array[++i];
}

void	big_to_a(t_info **a, t_info **b, t_elem  **el, int *array)
{
	int	i;

	i = 0;
	//(*el)->flag++;
	printf("%d flag \n", (*el)->flag);
	printf("%d mid \n", (*el)->middle);
	printf("%d max \n", (*el)->max);
	printf("%d mid \n", (*el)->middle);
	printf("%d min \n", (*el)->min);
	print(*b, 'a');
	print(*a, 'b');

	while ((*a) && i <= (*el)->argc)
	{
		(*a)->flag = (*el)->flag;
		if ((*a)->value == (*el)->min)
		{
			printf("%d min \n", (*el)->min);
			next_elem(array, el, a);
			pa_pb(b, a, 'a', el);
			ra_rb(b, 'a', el);
		}
		else if ((*a)->value > (*el)->middle)
		{
			pa_pb(b, a, 'a', el);
			(*b) = (*b)->next;
		}
		else
			ra_rb(a, 'b', el);
		i++;
	}
}

void move_to_b(t_info **a, t_info **b, t_elem  **el, int *array)
{
	int	i;

	i = 0;
	while (((*a)->flag == (*a)->next->flag) && ((*a)->next != NULL))
	{
		pa_pb(b, a, 'b', el);
		if ((*b)->value >= (*el)->max)
			(*el)->max = (*b)->value;
		if ((*b)->value <= (*el)->min)
			(*el)->min = (*b)->value;
	}
	pa_pb(b, a, 'b', el);
	if ((*b)->value >= (*el)->max)
		(*el)->max = (*b)->value;
	if ((*b)->value <= (*el)->min)
		(*el)->min = (*b)->value;
	elem_init_2(el, *b, array);
	while (*b)
	{
		big_to_a(b, a, el, array);
		elem_init_2(el, *b, array);
	}
}