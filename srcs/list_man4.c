/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_man4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:04:22 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/17 10:08:24 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Finds median value of the list
**	Find median High
**	Find and remove min, find and remove max, until len(1)
*/

int			get_median(t_int_list *list)
{
	t_int_list	*tmp;
	int			nb;
	t_int_list	*node;

	tmp = copy_list(list);
	while (count_list(tmp) > 1)
	{
		nb = find_min(tmp);
		node = extract_nb(&tmp, nb);
		clear_list(&node);
		if (count_list(tmp) == 1)
			break ;
		nb = find_max(tmp);
		node = extract_nb(&tmp, nb);
		clear_list(&node);
	}
	nb = tmp->nb;
	clear_list(&tmp);
	return (nb);
}

/*
**	Suffixes list b to list a and returns pointer to the head of a
*/

t_int_list	*ps_join_lsts(t_int_list *a, t_int_list *b)
{
	t_int_list *tmp;

	tmp = a;
	if (!tmp)
		return (b);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = b;
	return (a);
}

/*
**	Finds a value in given lists and extracts that node
*/

t_int_list	*extract_nb(t_int_list **head, int nb)
{
	t_int_list	*node;
	t_int_list	*current;

	if (!*head)
		return (NULL);
	current = *head;
	if (current->nb == nb)
		return (extract_first(head));
	while (current->next)
	{
		if (current->next->nb == nb)
		{
			node = current->next;
			current->next = node->next;
			node->next = NULL;
			return (node);
		}
		else
			current = current->next;
	}
	return (NULL);
}

/*
**	Copy list
*/

t_int_list	*copy_list(t_int_list *list)
{
	t_int_list *res;

	res = NULL;
	while (list)
	{
		res = create_back(res, list->nb);
		list = list->next;
	}
	return (res);
}
