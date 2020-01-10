/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_man2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:04:22 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/10 09:49:33 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int			find_min(t_int_list *list)
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

int			find_max(t_int_list *list)
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

int			count_list(t_int_list *list)
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
