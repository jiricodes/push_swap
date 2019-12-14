/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:04:22 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/12 18:40:22 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Creates a node for t_int_list
*/

t_int_list	*create_node(int nb)
{
	t_int_list *node;

	node = (t_int_list*)malloc(sizeof(t_int_list));
	if (!node)
		error_exit("malloc @create_node");
	node->nb = nb;
	node->next = NULL;
	return (node);
}

/*
** Add a node to the beginning of a list
*/

t_int_list	*add_front(t_int_list *head, t_int_list *node)
{
	if (!head)
		return (node);
	node->next = head;
	return (node);
}

/*
** Add a node to the end of a list
*/

t_int_list	*add_back(t_int_list *head, t_int_list *node)
{
	t_int_list *tmp;

	if (!head)
		return (node);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (head);
}

/*
**	Create a node at the first position;
*/

t_int_list	*create_front(t_int_list *head, int nb)
{
	t_int_list *node;

	node = create_node(nb);
	return (add_front(head, node));
}

/*
**	Create a node at the last position;
*/

t_int_list	*create_back(t_int_list *head, int nb)
{
	t_int_list *node;

	node = create_node(nb);
	return (add_back(head, node));
}

/*
** Extract First
*/

t_int_list	*extract_first(t_int_list **head)
{
	t_int_list *first;

	if (!head || !*head)
		return (NULL);
	if (!(*head)->next)
	{
		first = *head;
		*head = NULL;
	}
	else
	{
		first = *head;
		*head = (*head)->next;
		first->next = NULL;
	}
	return (first);
}

/*
** Extract Last
*/

t_int_list	*extract_last(t_int_list **head)
{
	t_int_list *current;
	t_int_list *last;

	if (!head || !*head)
		return (NULL);
	if (!(*head)->next)
	{
		last = *head;
		*head = NULL;
	}
	else
	{
		current = *head;
		while (current->next->next)
			current = current->next;
		last = current->next;
		current->next = NULL;
	}
	return (last);
}
