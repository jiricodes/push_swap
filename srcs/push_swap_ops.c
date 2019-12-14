/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:17:33 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/12 18:20:07 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int_list	*swap_top2(t_int_list *list)
{
	t_int_list *tmp;

	if (!list || !list->next)
		return (list);
	tmp = list->next;
	list->next = tmp->next;
	tmp->next = list;
	return (tmp);
}

void		push(t_int_list **dest, t_int_list **src)
{
	t_int_list *tmp;

	if (!src || !*src)
		return ;
	if (!dest || !*dest)
		*dest = extract_first(src);
	else
	{
		tmp = *dest;
		*dest = extract_first(src);
		(*dest)->next = tmp;
	}
}

t_int_list	*rotate(t_int_list *list)
{
	t_int_list *tmp;

	tmp = extract_first(&list);
	return (add_back(list, tmp));
}

t_int_list	*rev_rotate(t_int_list *list)
{
	t_int_list *tmp;

	tmp = extract_last(&list);
	return (add_front(list, tmp));
}
