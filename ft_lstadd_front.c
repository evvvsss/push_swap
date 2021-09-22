#include "push_swap.h"

void	ft_lstadd_front(t_info **lst, t_info *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
