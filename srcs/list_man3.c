/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_man3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:04:22 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/10 09:50:08 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (find_nb_pos(list, max) + 1);
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
