/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sortop3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:08:04 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 19:44:36 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sort top 3 of stack A
** Only these possibilities:
** 132 213 231 312 321
*/

static int	ps_sort_top3a2(t_ps *ps)
{
	if (A_3RD > A_2ND && A_TOP > A_3RD)
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

int			ps_sort_top3a(t_ps *ps)
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
	else
		return (ps_sort_top3a2(ps));
}

/*
** Sorts 3 on stack A
** Only these possibilities:
** 132 213 321
*/

int			ps_a_sort3(t_ps *ps)
{
	if (!is_rot_sort(ps->a))
		do_sa(ps);
	return (find_max(A_LST));
}
