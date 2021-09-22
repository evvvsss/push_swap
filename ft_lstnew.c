#include "push_swap.h"

t_info	*ft_lstnew(int value)
{
	t_info	*list;

	list = (t_info *)malloc(sizeof(t_info));
	if (list == NULL)
		return (0);
	list->value = value;
	list->index = -1;
	list->flag = 0;
	list->next = NULL;
	return (list);
}