/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:04:22 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/16 14:58:03 by jnovotny         ###   ########.fr       */
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

/*
** List mMIN
*/

int	find_min(t_int_list *list)
{
	int min;

	min = INT_MAX;
	while (list)
	{
		min > list->nb ? min = list->nb : 0;
		list = list->next;
	}
	return (min);
}

/*
** List MAX
*/

int	find_max(t_int_list *list)
{
	int max;

	max = INT_MIN;
	while (list)
	{
		max < list->nb ? max = list->nb : 0;
		list = list->next;
	}
	return (max);
}

/*
** Returns amount of nodes in a list
*/

int	count_list(t_int_list *list)
{
	int cnt;

	cnt = 0;
	while (list)
	{
		cnt++;
		list = list->next;
	}
	return (cnt);
}

/*
** Returns amount of commands in the list
*/

int	count_cmd_list(t_cmd *list)
{
	int cnt;

	cnt = 0;
	while (list)
	{
		cnt++;
		list = list->next;
	}
	return (cnt);
}

/*
** Returns value of the last node
*/

int	get_last(t_int_list *list)
{
	while (list->next)
		list = list->next;
	return (list->nb);
}

/*
** Checks if the int list is valaid (cannot contain duplicates)
*/

int	check_valid(t_int_list *list)
{
	t_int_list *tmp;

	while (list)
	{
		tmp = list->next;
		while (tmp)
		{
			if (list->nb == tmp->nb)
				return (0);
			tmp = tmp->next;
		}
		list = list->next;
	}
	return (1);
}

/*
** Finds position of given value
*/

int	find_nb_pos(t_int_list *list, int nb)
{
	int		i;

	i = 1;
	while (list && list->nb != nb)
	{
		list = list->next;
		i++;
	}
	if (list)
		return (i);
	else
		return (-1);
}

int	find_slot_rotsort(t_int_list *list, int nb, int max)
{
	int		i;

	if (nb > max)
		return (find_nb_pos(list, max));
	i = 1;
	while (list && list->next)
	{
		if (nb > list->nb && nb < list->next->nb)
			return (i);
		list = list->next;
		i++;
	}
	return (i);
}
