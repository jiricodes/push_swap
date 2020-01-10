/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_insertsort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:53:26 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/09 14:06:19 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Based on define RUN_SIZE pushes items from stack A to stack B so
** the B stack is reverse ordered and contains at least RUN_SIZE number
*/

void	ps_insertsort(t_ps *ps, int rotation)
{
	/*
	** check slot -> ra or rb
	** what if rr or rrr and pb is faster?
	** try to check for sa then pb rather than smart pb
	*/
	int i;

	i = 0;
	ps_info(ps);
	if (rotation > 0)
	{
		while (i < RUN_SIZE && !is_rot_sort(ps->a))
		{
			do_smartpush_b(ps);
			i++;
		}
	}
	else
	{
		while (i < RUN_SIZE && !is_rot_sort(ps->a))
		{
			do_rra(ps);
			do_smartpush_b(ps);
			i++;
		}
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

/*
** Finds first unsorted breakpoint.
** returns 0 if no rotation required.
** 1 if rotation required
** -n if reversed rotation required
*/

int		find_unsorted(t_ps *ps)
{
	int i;

	i = find_unsort_index(ps);
	if (is_rot_sort(ps->a))
		return (0);
	else if (i == 0)
		return (1);
	else if (i < RUN_SIZE && RUN_SIZE < A_CNT)
		return (1);
	else if (i > RUN_SIZE)
		return (A_CNT - i < RUN_SIZE ? -1 * (A_CNT - i) : -1 * RUN_SIZE);
	else if (i < A_CNT / 2)
		return (1);
	else
		return (-1 * RUN_SIZE);
}

int		find_unsort_index(t_ps *ps)
{
	t_int_list	*tmp;
	int			i;

	tmp = A_LST;
	i = 0;
	while (tmp)
	{
		if (tmp->next && tmp->nb > tmp->next->nb)
			if (tmp->nb != A_MAX || tmp->next->nb != A_MIN)
				break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

/*
** Checks if operation SA would make the list sorted
*/

static int		check_safix(t_ps *ps)
{
	if (A_LAST < A_2ND && A_TOP > A_2ND)
		return (1);
	else
		return (0);
}

/*
** Prepares stack in position for insertsort
** returns 0 if no insertsort is needed at this point
** otherwise it returns run_size for insertsort
*/

int		ps_pars_rotate(t_ps *ps)
{
	int		brk;

	brk = find_unsorted(ps);
	if (brk <= 0)
		return (brk);
	else
	{
		if (A_TOP < A_2ND)
		{
			do_ra(ps);
			while (A_TOP > A_LAST)
				do_ra(ps);
		}
		if (check_safix(ps))
		{
			do_sa(ps);
			return (0);
		}
		else
			return (1);
	}
}
