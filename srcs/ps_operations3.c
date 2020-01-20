/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:49:39 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 15:52:19 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			do_ra_i(t_ps *ps, int i)
{
	while (i-- > 0)
		do_ra(ps);
}

void			do_rb_i(t_ps *ps, int i)
{
	while (i-- > 0)
		do_rb(ps);
}

void			do_rra_i(t_ps *ps, int i)
{
	while (i++ < A_CNT)
		do_rra(ps);
}

void			do_rrb_i(t_ps *ps, int i)
{
	while (i++ < B_CNT)
		do_rrb(ps);
}
