#include "push_swap.h"

void	elem_init_0(t_elem **el, int argc)
{
	(*el) = (t_elem *)malloc(sizeof(t_elem));
	(*el)->argc = 0;
	(*el)->counter = 0;
	if (argc < 102)
		(*el)->add = 15;
	else
		(*el)->add = 30;
}

int	check_repeats(t_info *a, int digit)
{
	while (a)
	{
		if (a->value == digit)
			return (1);
		a = a->next;
	}
	return (0);
}

int	find_index(int val, t_info *a, t_elem *el)
{
	int	i;

	i = 1;
	while (a && i < el->argc)
	{
		if (a->value == val)
			return (i);
		a = a->next;
		i++;
	}
	return (0);
}

int	find_elem(int index, t_info *a)
{
	int	i;

	i = 1;
	while (a)
	{
		if (a->index == index)
			return (i);
		a = a->next;
		i++;
	}
	return (0);
}

void index_to_lists(int *array, t_info **a)
{
	int		i;
	t_info	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		while (tmp->value != array[i])
			i++;
		tmp->index = i;
		tmp = tmp->next;
		i = 0;
	}
}

int max_index(t_info *a)
{
	int	max;

	max = 0;
	if (a)
	{
		max = a->index;
		while (a)
		{
			if (max < a->index)
				max = a->index;
			a = a->next;
		}
	}
	return (max);
}
