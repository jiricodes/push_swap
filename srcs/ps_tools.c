/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:55:45 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/07 17:19:12 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_smart_rotate_a(t_ps *ps)
{
	int			i;

	i = find_nb_pos(A_LST, A_MIN);
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

// void	insert_extreme_b(ps)
// {
	
// }

void	do_smartpush_b(t_ps *ps)
{
	int	p;

	if (B_CNT < 2)
	{
		do_pb(ps);
		return ;
	}
	// if (A_TOP < B_MIN || A_TOP > B_MAX)
	// {
	// 	insert_extreme_b(ps);
	// 	if (!is_rev_rot_sort(ps->b))
	// 	{
	// 		ft_printf("{RED}{B}ERROR @smartpush_b after extreme insertion!{EOC}\n");
	// 		print_list(B_LST, "b not_revrotsort", ' ');
	// 		exit(0);
	// 	}
	// 	return ;
	// }
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