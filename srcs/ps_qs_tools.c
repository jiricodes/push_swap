/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_qs_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:28:37 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 18:15:27 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Insertsort from stack B to stack A
*/

static int	qs_best_rot(t_ps *ps, int pos_a, int pos_b)
{
	t_point best;

	best.x = INT_MAX;
	best.y = 0;
	if (qs_bestcheck(pos_a, pos_b, best.x))
	{
		best.x = pos_a > pos_b ? pos_a : pos_b;
		best.y = 1;
	}
	if (qs_bestcheck(A_CNT - pos_a, B_CNT - pos_b, best.x))
	{
		best.x = A_CNT - pos_a > B_CNT - pos_b ? A_CNT - pos_a : B_CNT - pos_b;
		best.y = 2;
	}
	if ((pos_a + B_CNT - pos_b) < best.x)
	{
		best.x = pos_a + B_CNT - pos_b;
		best.y = 3;
	}
	if ((pos_b + A_CNT - pos_a) < best.x)
	{
		best.x = pos_b + A_CNT - pos_a;
		best.y = 4;
	}
	return (best.y);
}

static void	qs_syncstacks(t_ps *ps, int a, int b)
{
	int mode;

	mode = qs_best_rot(ps, a, b);
	if (mode == 0)
		error_exit("Stacks cannot be synced @qs_syncstacks");
	else if (mode == 1)
	{
		do_ra_i(ps, a);
		do_rb_i(ps, b);
	}
	else if (mode == 2)
	{
		do_rra_i(ps, a);
		do_rrb_i(ps, b);
	}
	else if (mode == 3)
	{
		do_ra_i(ps, a);
		do_rrb_i(ps, b);
	}
	else if (mode == 4)
	{
		do_rra_i(ps, a);
		do_rb_i(ps, b);
	}
}

void		qs_insertsort(t_ps *ps)
{
	int	best;
	int a;
	int b;

	best = A_CNT != 3 ? qs_insert_optimal(ps) : B_MAX;
	// best = qs_insert_optimal(ps);
	b = find_nb_pos(B_LST, best);
	a = qs_find_slot(A_LST, best);
	qs_syncstacks(ps, a, b);
	do_pa(ps);
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
