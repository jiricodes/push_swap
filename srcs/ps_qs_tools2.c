/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_qs_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:28:37 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 16:17:25 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
** Rotate B to position
*/

void		ps_merge_rotate_b(t_ps *ps, int pos)
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
