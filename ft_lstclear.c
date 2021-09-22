#include "push_swap.h"

void	ft_lstclear(t_info **lst)
{
	t_info	*element;

	while (*lst)
	{
		element = *lst;
		*lst = element->next;
		free(element);
	}
	lst = NULL;
}
