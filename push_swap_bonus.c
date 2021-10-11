#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int	*add_array(t_info *a, t_elem *el)
{
	int	i;
	int	sort;
	int	*b;

	i = 0;
	sort = 0;
	b = malloc(el->argc * sizeof(int));
	if (!b)
		return (NULL);
	while (a)
	{
		b[i] = a->value;
		if (a->next != NULL && (a->value > a->next->value))
			sort++;
		a = a->next;
		i++;
	}
	if (sort != 0)
		return (b);
	else
	{
		ft_clear(&a, &el);
		return (NULL);
	}
}

void	ft_clear(t_info **a, t_elem **el)
{
	ft_lstclear(a);
	a = NULL;
	free(*el);
	(*el) = NULL;
}

int	main(int argc, char **argv)
{
	t_info	*a;
	t_info	*b;
	t_elem	*el;
	int		i;
	int		*array;

	i = 1;
	if (argc < 2)
		return (0);
	elem_init_0(&a, &b, &el, argc);
	while (argc > i)
	{
		if (check_args(argv[i], &a, &el) == 1)
		{	
			write(2, "Error\n", 6);
			ft_clear(&a, &el);
			return (0);
		}
		i++;
	}
	array = add_array(a, el);
	if (!array)
		return (0);
	main_part(&array, &a, &b, &el);
	return (0);
}
