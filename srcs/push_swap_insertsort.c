/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_insertsort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:53:26 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/07 17:34:57 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Based on define RUN_SIZE pushes items from stack A to stack B so
** the B stack is reverse ordered and contains at least RUN_SIZE number
*/

void	ps_insertsort(t_ps *ps)
{
	/*
	** check slot -> ra or rb
	** what if rr or rrr and pb is faster?
	** try to check for sa then pb rather than smart pb
	*/
	int i;

	i = 0;
	ps_info(ps);
	while (i < RUN_SIZE && !is_rot_sort(ps->a))
	{
		do_smartpush_b(ps);
		i++;
	}
}

void	ps_merge(t_ps *ps)
{
	/*
	**
	** sync positions
	** 		find index max on B
	**		find the slot on A
	**		if both same direction then rr or rrr
	**		else
	**			test if move in direction of the one requiring more steps
	**			would decrese amount of steps needed to rotate
	**			after for the other one
	** once synced push A one
	** while B_LST
	** 		zipping check
	**			rotate
	**			continue
	**		else
	**			push A
	*/

	int	slot;
	int pos;
	int	i;

	ps_info(ps);
	pos = find_nb_pos(B_LST, B_MAX);
	slot = find_slot_rotsort(A_LST, B_MAX, A_MAX, A_MIN);
	ft_printf("@merge: pos_Bmax = %d | A_slot = %d\n", pos, slot);
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
	while (B_LST)
	{
		if (A_LAST < A_TOP && A_LAST > B_TOP)
			do_rra(ps);
		else
			do_pa(ps);
	}
}