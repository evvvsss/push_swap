/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:27:33 by bferny            #+#    #+#             */
/*   Updated: 2021/10/12 21:27:34 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*ft_lstnew(int value)
{
	t_info	*list;

	list = (t_info *)malloc(sizeof(t_info));
	if (list == NULL)
		return (0);
	list->value = value;
	list->index = -1;
	list->next = NULL;
	return (list);
}
