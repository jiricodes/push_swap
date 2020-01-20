/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 10:34:13 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 19:33:46 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks Whether the given list is sorted
*/

int		is_sort_list(t_int_list *list)
{
	while (list->next)
	{
		if (list->nb > list->next->nb)
			return (0);
		list = list->next;
	}
	return (1);
}

/*
** Checker binary output (a is sorted and b is null)
*/

void	is_correct_ps(t_int_list *a, t_int_list *b)
{
	if (is_sort_list(a) && b == NULL)
		ft_printf("{GREEN}{B}OK{EOC}\n");
	else
		ft_printf("{RED}{B}KO{EOC}\n");
}

/*
** Check whether a list is sorted, but rotated (min after max).
** Returns the position of min value.
*/

int		is_rot_sort(t_stk *stack)
{
	t_int_list	*tmp;
	int			i;
	int			res;

	i = 1;
	res = i;
	tmp = stack->lst;
	if (tmp && tmp->nb != stack->min && tmp->nb < get_last(tmp))
		return (0);
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
		{
			if (tmp->nb == stack->max && tmp->next->nb == stack->min)
			{
				res = i + 1;
				tmp = tmp->next;
				continue;
			}
			return (0);
		}
		tmp = tmp->next;
		i++;
	}
	return (res);
}

/*
** Check whether a list is reverse sorted, but rotated (max after min).
** Returns the position of max value.
*/

int		is_rev_rot_sort(t_stk *stack)
{
	t_int_list	*tmp;
	int			i;
	int			res;

	i = 1;
	res = i;
	tmp = stack->lst;
	if (tmp && tmp->nb != stack->max && tmp->nb > get_last(tmp))
		return (0);
	while (tmp && tmp->next)
	{
		if (tmp->nb < tmp->next->nb)
		{
			if (tmp->nb == stack->min && tmp->next->nb == stack->max)
			{
				res = i + 1;
				tmp = tmp->next;
				continue;
			}
			return (0);
		}
		tmp = tmp->next;
		i++;
	}
	return (res);
}

/*
** Returns position where a given number could be placed in a sorted list.
** In unsorted list the return value is the first valid position.
*/

int		find_slot(t_int_list *list, int nb)
{
	int		pos;

	pos = 1;
	while (list && nb > list->nb)
	{
		pos++;
		list = list->next;
	}
	return (pos);
}
