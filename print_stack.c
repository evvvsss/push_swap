#include "push_swap.h"

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
