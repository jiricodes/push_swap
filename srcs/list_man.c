/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:04:22 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/21 19:22:53 by jnovotny         ###   ########.fr       */
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

	i = 0;
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

/*
** Finds a slot for given number in rotated sorted list (asc)
*/

int	find_slot_rotsort(t_int_list *list, int nb, int max, int min)
{
	int		i;

	if (nb > max)
		return (find_nb_pos(list, max));
	else if (nb < min)
		return (find_nb_pos(list, min));
	i = 0;
	while (list && list->next)
	{
		if (nb > list->nb && nb < list->next->nb)
			return (i);
		list = list->next;
		i++;
	}
	return (i);
}

/*
** Finds a slot for given number in rotated sorted list (desc)
*/

int	find_slot_rev_rotsort(t_int_list *list, int nb, int max, int min)
{
	int		i;

	if (nb > max)
		return (find_nb_pos(list, max));
	else if (nb < min)
		return (find_nb_pos(list, min) + 1);
	i = 0;
	if (!list || (nb > list->nb && nb < get_last(list)))
		return (i);
	while (list && list->next)
	{
		i++;
		if (nb < list->nb && nb > list->next->nb)
			return (i);
		list = list->next;
	}
	return (i);
}

/*
**	Finds median value of the list
*/

int	get_median(t_int_list *list)
{
	int		cnt;
	int		tot;

	cnt = 0;
	tot = 0;
	while (list)
	{
		cnt++;
		tot += list->nb;
		list = list->next;
	}
	return (tot / cnt);
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
