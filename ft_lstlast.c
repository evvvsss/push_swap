#include "push_swap.h"

t_info	*ft_lstlast(t_info *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
