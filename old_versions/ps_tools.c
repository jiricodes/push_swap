/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:55:45 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 15:59:11 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Final rotation of sorted list into proper position (min at the top)
*/

void	ps_smart_rotate_a(t_ps *ps)
{
	int			i;

	i = find_nb_pos(A_LST, A_MIN);
	qs_rot_a(ps, i);
}

/*
** Checks if ss or sa or sb is a viable option
*/

int		check_switches_front(t_ps *ps, int pos)
{
	int pos2;

	if (pos == 0)
		return (0);
	pos2 = find_slot_rev_rotsort(B_LST, A_2ND, B_MAX, B_MIN);
	if (pos < B_CNT / 2 && (pos2 < (pos - 1) || (A_CNT - pos2) < pos))
	{
		do_sa(ps);
		return (1);
	}
	else if (pos >= B_CNT / 2 && (pos2 > (pos + 1) || (A_CNT - pos) > pos2))
	{
		do_sa(ps);
		return (1);
	}
	else
		return (0);
}

int		check_switches_back(t_ps *ps, int pos)
{
	int pos2;

	if (pos == 0)
		return (0);
	pos2 = find_slot_rev_rotsort(B_LST, A_LAST, B_MAX, B_MIN);
	if (pos < B_CNT / 2 && (pos2 < (pos - 1) || (A_CNT - pos2) < pos))
	{
		do_rra(ps);
		do_smartpush_b_nc(ps);
		return (1);
	}
	else if (pos >= B_CNT / 2 && (pos2 > (pos + 1) || (A_CNT - pos) > pos2))
	{
		do_rra(ps);
		do_smartpush_b_nc(ps); // fix!
		return (1);
	}
	else
		return (0);
}

/*
** Does PB in such fashion that stack B is always sorted
*/

void	do_smartpush_b(t_ps *ps)
{
	int	p;

	if (B_CNT < 2)
	{
		do_pb(ps);
		return ;
	}
	p = find_slot_rev_rotsort(B_LST, A_TOP, B_MAX, B_MIN);
	if (p < B_CNT / 2)
	{
		if (check_switches_front(ps, p))
		{
			do_smartpush_b(ps);
			return ;
		}
		while (p-- > 0)
			do_rb(ps);
	}
	else
	{
		if (check_switches_back(ps, p))
			return ;
		p = find_slot_rev_rotsort(B_LST, A_TOP, B_MAX, B_MIN);
		while (p++ < B_CNT)
			do_rrb(ps);
	}
	do_pb(ps);
	if (!is_rev_rot_sort(ps->b))
	{
		ft_printf("{RED}{B}ERROR @smartpush_b!{EOC}\n");
		print_list(B_LST, "not revsort B", ' ');
		exit(0);
	}
}

/*
** Does PB in such fashion that stack B is always sorted
*/

void	do_smartpush_b_nc(t_ps *ps)
{
	int	p;

	if (B_CNT < 2)
	{
		do_pb(ps);
		return ;
	}
	p = find_slot_rev_rotsort(B_LST, A_TOP, B_MAX, B_MIN);
	if (p < B_CNT / 2)
	{
		while (p-- > 0)
			do_rb(ps);
	}
	else
		while (p++ < B_CNT)
			do_rrb(ps);
	do_pb(ps);
	if (!is_rev_rot_sort(ps->b))
	{
		ft_printf("{RED}{B}ERROR @smartpush_b!{EOC}\n");
		print_list(B_LST, "not revsort B", ' ');
		exit(0);
	}
}
