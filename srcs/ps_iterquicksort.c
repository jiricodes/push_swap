/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_iterquicksort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:28:37 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 17:31:06 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Splitter
*/

int		qs_split_range(t_ps *ps, int left, int right, int len)
{
	ps_info(ps);
	while (qs_contains(A_LST, left, right))
	{
		if (count_list(A_LST) == 3)
		{
			ps_sort_top3a(ps);
			break ;
		}
		if (left < A_TOP && A_TOP <= right)
			do_pb(ps);
		else
			do_ra(ps);
	}
	return (len - count_list(B_LST));
}

/*
**	Merge
*/

int		qs_merge(t_ps *ps)
{
	int		left;

	ps_info(ps);
	left = B_MAX;
	if (B_TOP < A_MIN && B_MAX < A_MIN && !is_rot_sort(ps->a))
		do_pa(ps);
	while (B_LST)
	{
		qs_insertsort(ps);
		ps_info(ps);
	}
	return (left);
}

/*
** Counts the amount of numbers n such left <= n < right
*/

int		qs_runlenght(t_int_list *list, int left, int right)
{
	t_int_list	*tmp;
	int			count;

	tmp = list;
	count = 0;
	while (tmp)
	{
		if (tmp->nb > left && tmp->nb <= right)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

/*
** Returns first value of the Runs list, and removes the node
*/

int		qs_nextrun(t_int_list **runs)
{
	t_int_list	*tmp;
	int			res;

	if (!runs || !*runs)
		return (-1);
	tmp = extract_first(runs);
	res = tmp->nb;
	clear_list(&tmp);
	return (res);
}

/*
** Bool function to determine whether the list contains numbers such:
** left <= number < right
*/

int		qs_contains(t_int_list *list, int left, int right)
{
	t_int_list *tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->nb > left && tmp->nb <= right)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}
