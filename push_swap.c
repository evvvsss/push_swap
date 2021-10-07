#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	print(t_info *a, char n)
{
	if (n == 'a')
		printf("\n%s", "Стек А ");
	if (n == 'b')
		printf("\n%s", "Стек B ");
	if (!a)
	{
		printf("%s\n", "is empty :(");
		return ;
	}
	while (a)
	{
		printf(" %d ", a->value);
		printf("%d ", a->index);
		a = a->next;
	}
	printf("\n");
}

int	*add_array( t_info *a, t_elem *el)
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
		return (NULL);
}

int	check_args(char *argv, t_info **a, t_elem **el)
{
	int		j;
	int		space;
	char	**b;

	j = 0;
	space = 0;
	b = NULL;
	while (argv[j] != '\0')
	{
		if (!(argv[j] >= '0' && argv[j] <= '9'))
		{
			if (argv[j] == ' ')
				space++;
			else if ((argv[j] == '+' || argv[j] == '-'))
			{
				if (!(argv[j + 1] >= '0' && argv[j + 1] <= '9'))
					return (1);
			}
			else
				return (1);
		}
		j++;
	}
	j = 0;
	if (space != 0)
	{
		b = ft_split(argv, ' ');
		while (b[j] != NULL)
		{
			if (check_repeats(*a, ft_atoi(b[j], el)) == 1 || (*el)->counter == -5)
				return (1);
			ft_lstadd_back(a, ft_lstnew(ft_atoi(b[j], el)));
			((*el)->argc)++;
			j++;
		}
	}
	else
	{
		if (check_repeats(*a, ft_atoi(argv, el)) == 1 || (*el)->counter == -5)
			return (1);
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv, el)));
		(*el)->argc++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	*a;
	t_info	*b;
	t_elem	*el;
	int		i;
	int		*array;

	i = 1;
	a = NULL;
	b = NULL;
	elem_init_0(&el, argc);
	while (argc > i)
	{
		if (check_args(argv[i], &a, &el) == 1)
		{	
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	array = add_array(a, el);
	if (!array)
	{
		printf("Массив отсортирован\nВСЕГО ОПЕРАЦИЙ: %d \n", el->counter);
		return (0);
	}
	// print(a, 'a');
	sort_array(&array, 0, el->argc - 1);
	index_to_lists(array, &a);
	// print(a, 'a');
	// while (sorting_check(a, array) == 1)
	// {	
		sort_a(&a, &b, &el);
		// printf("ARGC  %d \n", el->argc);
		sort_b(&a, &b, &el, 0);
	// }
	print(a, 'a');
	print(b, 'b');
	 printf("ВСЕГО ОПЕРАЦИЙ: %d \n", el->counter);
	return (0);
}
