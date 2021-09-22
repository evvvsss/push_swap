#include "push_swap.h"

t_info	*ft_lst_copy(t_info	*l)
{
	t_info	*list;

	list = (t_info *)malloc(sizeof(t_info));
	if (list == NULL)
		return (0);
	list->value = l->value;
	list->index = l->index;
	list->flag = l->flag;
	list->next = NULL;
	return (list);
}