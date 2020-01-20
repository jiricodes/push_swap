/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:26:26 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 14:27:31 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pb(t_ps *ps)
{
	push(&(B_LST), &(A_LST));
	CMD = create_cmd_back(CMD, "pb");
	ps_info(ps);
}

void	do_pa(t_ps *ps)
{
	push(&(A_LST), &(B_LST));
	CMD = create_cmd_back(CMD, "pa");
	ps_info(ps);
}

void	do_sa(t_ps *ps)
{
	A_LST = swap_top2(A_LST);
	CMD = create_cmd_back(CMD, "sa");
}

void	do_sb(t_ps *ps)
{
	B_LST = swap_top2(B_LST);
	CMD = create_cmd_back(CMD, "sb");
}

void	do_ra(t_ps *ps)
{
	A_LST = rotate(A_LST);
	CMD = create_cmd_back(CMD, "ra");
}
