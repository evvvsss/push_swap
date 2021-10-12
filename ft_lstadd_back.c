/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:27:07 by bferny            #+#    #+#             */
/*   Updated: 2021/10/12 21:27:08 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
