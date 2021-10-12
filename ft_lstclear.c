/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:27:21 by bferny            #+#    #+#             */
/*   Updated: 2021/10/12 21:27:22 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
