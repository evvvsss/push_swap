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
		printf("%d ", a->flag);
		printf("%d ", a->index);
		a = a->next;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	t_info	*a;
	t_info	*b;
	t_elem	*el;
	t_info	*c;
	int		i;
	int		*array;

	i = 1;
	array = malloc(argc * sizeof(int));
	//check
	a = NULL;
	b = NULL;
	c = NULL;
	while (argc > i)
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
		array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	array[i - 1] = '\0';

	// i = 0;
	// while (array[i] != '\0')
	// {
	// 	printf("\nAAAAAAAAAA\n%d %d ", array[i], i);
	// 	i++;
	// }
	sort(&array, 0, i - 2);
	elem_init_1(&el, array, argc - 2);
	print(a, 'a');
	print(b, 'b');
	small_to_b(&a, &b,  &el, el->argc);
	el->max = el->middle;
	print(a, 'a');
	print(b, 'b');
	elem_init_2(&el, b, array);
	el->min = array[0];
	while (b)
	{	
		big_to_a(&b, &a, &el, array);
		elem_init_2(&el, b, array);
		print(b, 'b');
	}
	// while (b)
	// {	
	// 	big_to_a(&b, &a,  &el, array);
	// 	elem_init_2(&el, b, array);
	// 	print(b, 'b');
	// }
	el->max = a->value;
	el->min = a->value;
	while (a->index < 0)
	{
		move_to_b(&a, &b, &el, array);
	}
	// move_to_b(&a, &b, &el, array);
	// move_to_b(&a, &b, &el, array);
	// move_to_b(&a, &b, &el, array);
	// move_to_b(&a, &b, &el, array);
	// move_to_b(&a, &b, &el, array);
	// print(a, 'a');
	// print(b, 'b');
	
	//move_to_b(&a, &b, &el, array);
	print(a, 'a');
	print(b, 'b');
	printf("ВСЕГО ОПЕРАЦИЙ: %d \n", el->counter);
}