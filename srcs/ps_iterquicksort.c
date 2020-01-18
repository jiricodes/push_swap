/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_iterquicksort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:28:37 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/17 19:55:56 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Splitter
*/

int		qs_split_range(t_ps *ps, int left, int right, int len)
{

	ps_info(ps);
	// include check for oneoff and sa
	while (qs_contains(A_LST, left, right))
	{
		if (count_list(A_LST) == 3)
		{
			ps_sort_top3a(ps);
			break;
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
static void	ps_merge_rotate_b(t_ps *ps, int pos)
{
	int i;

	if (B_CNT == 1)
		return ;
	if (pos <= B_CNT / 2)
	{
		i = 0;
		while (i < pos)
		{
			do_rb(ps);
			i++;
		}
	}
	else
	{
		i = B_CNT;
		while (i > pos)
		{
			do_rrb(ps);
			i--;
		}
	}
}

int		qs_merge(t_ps *ps, t_int_list **runs)
{
	int		left;
	int		right;
	int		len;

	ps_info(ps);
	if (B_MIN > A_MIN)
		while (A_LAST > B_MAX)
			do_rra(ps);
	while (B_CNT > RUN_SIZE)
	{
		left = get_median(B_LST);
		right = B_MAX;
		len = qs_runlenght(B_LST, left, right);
		*runs = create_front(*runs, len);
		while (qs_contains(B_LST, left, right))
		{
			if (left < B_TOP && B_TOP <= right)
				do_pa(ps);
			else
				do_rb(ps);
		}
		ps_info(ps);
	}
	ps_info(ps);
	left = B_MAX;
	if (is_rot_sort(ps->a))
		{
			while (B_LST)
			{
				// this needs a optimization
				qs_rot_a(ps, find_slot_rotsort(A_LST, B_MAX, A_MAX, A_MIN));
				ps_merge_rotate_b(ps, find_nb_pos(B_LST, B_MAX));
				do_pa(ps);
				ps_info(ps);
			}
			return (left);
		}
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

/*
** Insertsort from stack B to stack A
*/

void	qs_insertsort(t_ps *ps)
{
	if (B_TOP < A_MIN || B_TOP > A_MAX)
	{
		ps_smart_rotate_a(ps);
		do_pa(ps);
		return ;
	}
	if (B_TOP < A_TOP && B_TOP > A_LAST)
		do_pa(ps);
	else if (B_TOP > A_TOP)
		do_ra(ps);
	else
		do_rra(ps);
}

/*
** Rotate A to a specific index
*/

void	qs_rot_a(t_ps *ps, int i)
{
	if (i < A_CNT / 2)
	{
		while (i > 0)
		{
			do_ra(ps);
			i--;
		}
	}
	else
	{
		while (i < A_CNT)
		{
			do_rra(ps);
			i++;
		}
	}
}

/*
**	Returns median of first N numbers of the list
*/

int		qs_get_median_range(t_int_list *list, int n)
{
	t_int_list	*tmp;
	int			res;

	if (n == 0)
		return (0);
	tmp = NULL;
	while (list && n > 0)
	{
		tmp = create_back(tmp, list->nb);
		list = list->next;
		n--;
	}
	res = get_median(tmp);
	clear_list(&tmp);
	return (res);
}

/*
** Checks if next N numbers of the list are sorted
*/

int		ps_check_sort_n(t_int_list *list, int len)
{
	while (list && len > 1)
	{
		if (list->next && list->nb > list->next->nb)
			return (FALSE);
		list = list->next;
		len--;
	}
	return (TRUE);
}

/*
** Returns [i] number of the list
*/

int		ps_get_i_val(t_int_list *list, int i)
{
	while (i-- > 0)
		list = list->next;
	return (list->nb);
}

/*
** Sort top 3 of stack A
** Only these possibilities:
** 132 213 231 312 321 
*/

int		ps_sort_top3a(t_ps *ps)
{
	if (A_TOP < A_3RD && A_2ND > A_3RD)
	{
		do_ra(ps);
		do_sa(ps);
		return (A_2ND);
	}
	else if (A_TOP > A_2ND && A_TOP < A_3RD)
	{
		do_sa(ps);
		return(A_3RD);
	}
	else if (A_TOP < A_2ND && A_TOP > A_3RD)
	{
		do_ra(ps);
		do_sa(ps);
		do_rra(ps);
		do_sa(ps);
		return (A_3RD);
	}
	else if (A_3RD > A_2ND && A_TOP > A_3RD)
	{
		do_sa(ps);
		do_ra(ps);
		do_sa(ps);
		return (A_2ND);
	}
	else if (A_3RD < A_2ND && A_TOP > A_2ND)
	{
		do_sa(ps);
		do_ra(ps);
		do_sa(ps);
		do_rra(ps);
		do_sa(ps);
		return (A_3RD);
	}
	else
		return (A_3RD);
}