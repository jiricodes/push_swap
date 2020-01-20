/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:26:26 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 14:27:21 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rb(t_ps *ps)
{
	B_LST = rotate(B_LST);
	CMD = create_cmd_back(CMD, "rb");
}

void	do_rra(t_ps *ps)
{
	A_LST = rev_rotate(A_LST);
	CMD = create_cmd_back(CMD, "rra");
}

void	do_rrb(t_ps *ps)
{
	B_LST = rev_rotate(B_LST);
	CMD = create_cmd_back(CMD, "rrb");
}
