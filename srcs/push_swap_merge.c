/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:53:26 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/10 11:00:41 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_merge_rotate_a(t_ps *ps, int slot)
{
	int i;

	if (slot < A_CNT / 2)
	{
		i = 0;
		while (i < slot)
		{
			do_ra(ps);
			i++;
		}
	}
	else
	{
		i = A_CNT;
		while (i > slot)
		{
			do_rra(ps);
			i--;
		}
	}
}

static void	ps_merge_rotate_b(t_ps *ps, int pos)
{
	int i;

	if (pos < B_CNT / 2)
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

void		ps_merge(t_ps *ps)
{
	int	slot;
	int pos;

	ps_info(ps);
	pos = find_nb_pos(B_LST, B_MAX);
	slot = find_slot_rotsort(A_LST, B_MAX, A_MAX, A_MIN);
	ps_merge_rotate_a(ps, slot);
	ps_merge_rotate_b(ps, pos);
	while (B_LST)
	{
		if (A_LAST < A_TOP && A_LAST > B_TOP)
			do_rra(ps);
		else
			do_pa(ps);
	}
}
