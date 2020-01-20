/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_iterquicksort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:28:37 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 15:00:39 by jnovotny         ###   ########.fr       */
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

int		qs_merge(t_ps *ps, t_int_list **runs)
{
	int		left;
	int		right;
	// int		len;

	// ps_info(ps);
	// if (B_MIN > A_MIN && B_CNT > RUN_SIZE)
	// 	while (A_LAST > B_MAX)
	// 		do_rra(ps);
	// while (B_CNT > RUN_SIZE)
	// {
	// 	left = get_median(B_LST);
	// 	right = B_MAX;
	// 	len = qs_runlenght(B_LST, left, right);
	// 	*runs = create_front(*runs, len);
	// 	while (qs_contains(B_LST, left, right))
	// 	{
	// 		if (left < B_TOP && B_TOP <= right)
	// 			do_pa(ps);
	// 		else
	// 			do_rb(ps);
	// 	}
	// 	ps_info(ps);
	// }
	right = (*runs)->nb;
	ps_info(ps);
	left = B_MAX;
	while (B_LST)
	{
		if (B_TOP < A_MIN && B_MAX < A_MIN && !is_rot_sort(ps->a))
			do_pa(ps);
		else
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

static int qs_best_rot(t_ps *ps, int pos_a, int pos_b)
{
	int best;
	int ret;

	best = INT_MAX;
	ret = 0;
	if (qs_bestcheck(pos_a, pos_b, best))
	{
		best = pos_a > pos_b ? pos_a : pos_b;
		ret = 1;
	}
	if (qs_bestcheck(A_CNT - pos_a, B_CNT - pos_b, best))
	{
		best = A_CNT - pos_a > B_CNT - pos_b ? A_CNT - pos_a : B_CNT - pos_b;
		ret = 2;
	}
	if ((pos_a + B_CNT - pos_b) < best)
	{
		best = pos_a + B_CNT - pos_b;
		ret = 3;
	}
	if ((pos_b + A_CNT - pos_a) < best)
	{
		best = pos_b + A_CNT - pos_a;
		ret = 4;
	}
	return (ret);
}

static void qs_syncstacks(t_ps *ps, int a, int b)
{
	int mode;

	mode = qs_best_rot(ps, a, b);
	if (mode == 0)
		error_exit("Stacks cannot be synced @qs_syncstacks");
	else if (mode == 1)
	{
		while (a-- > 0)
			do_ra(ps);
		while (b-- > 0)
			do_rb(ps);
	}
	else if (mode == 2)
	{
		while (a++ < A_CNT)
			do_rra(ps);
		while (b++ < B_CNT)
			do_rrb(ps);
	}
	else if (mode == 3)
	{
		while (a-- > 0)
			do_ra(ps);
		while (b++ < B_CNT)
			do_rrb(ps);
	}
	else if (mode == 4)
	{
		while (a++ < A_CNT)
			do_rra(ps);
		while (b-- > 0)
			do_rb(ps);
	}
}

void	qs_insertsort(t_ps *ps)
{
	int	best;
	int a;
	int b;

	best = qs_insert_optimal(ps);
	b = find_nb_pos(B_LST, best);
	a = qs_find_slot(A_LST, best);
	qs_syncstacks(ps, a, b);
	do_pa(ps);
}

/*
** Iterates through stack B and returns the number that
** requires the smallest amount of operations in order
** to be inserted on stack A in sorted manner.
*/

int			qs_bestcheck(int a, int b, int best)
{
	int max;

	max = a > b ? a : b;
	return (max < best);
}

static int	qs_curbest(t_ps *ps, int pos_a, int pos_b, int best)
{
	if (qs_bestcheck(pos_a, pos_b, best))
		best = pos_a > pos_b ? pos_a : pos_b;
	if (qs_bestcheck(A_CNT - pos_a, B_CNT - pos_b, best))
		best = A_CNT - pos_a > B_CNT - pos_b ? A_CNT - pos_a : B_CNT - pos_b;
	if ((pos_a + B_CNT - pos_b) < best)
		best = pos_a + B_CNT - pos_b;
	if ((pos_b + A_CNT - pos_a) < best)
		best = pos_b + A_CNT - pos_a;
	return (best);
}

int			qs_insert_optimal(t_ps *ps)
{
	int			best;
	int			best_dist;
	int			pos_a;
	int			pos_b;
	t_int_list	*tmp;

	best_dist = INT_MAX;
	best = 0;
	tmp = B_LST;
	while (tmp)
	{
		pos_a = qs_find_slot(A_LST, tmp->nb);
		pos_b = find_nb_pos(B_LST, tmp->nb);
		if (qs_curbest(ps, pos_a, pos_b, best_dist) < best_dist)
		{
			best = tmp->nb;
			best_dist = qs_curbest(ps, pos_a, pos_b, best_dist);
		}
		tmp = tmp->next;
	}
	return (best);
}

/*
** Find slot in unsorted list
*/

int			qs_find_slot(t_int_list *list, int nb)
{
	int i;

	i = 0;
	if (nb < find_min(list) || nb > find_max(list))
		return (find_nb_pos(list, find_min(list)));
	if (nb < list->nb && nb > get_last(list))
		return (i);
	while (list->next)
	{
		i++;
		if (list->nb < nb && list->next->nb > nb)
			break ;
		list = list->next;
	}
	return (i);
}

/*
** Rotate A to a specific index
*/

void	qs_rot_a(t_ps *ps, int i)
{
	if (i <= A_CNT / 2)
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
		return (A_3RD);
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

/*
** Rotate B to position
*/

void	ps_merge_rotate_b(t_ps *ps, int pos)
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
