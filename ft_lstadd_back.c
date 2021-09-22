#include "push_swap.h"

void	ft_lstadd_back(t_info **lst, t_info *new)
{
	t_info	*element;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	element = ft_lstlast(*lst);
	element->next = new;
	new->next = NULL;
}
