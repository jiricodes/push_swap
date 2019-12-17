/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfx_pushswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:53:30 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/17 12:56:54 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vfx_do_pushswap(t_ps *ps)
{
	while (ps->vfx_cmds)
	{
		cmd_to_func(&(ps->vfx_a->lst), &(ps->vfx_b->lst), ps->vfx_cmds->abbr);
		ps->vfx_cmds = ps->vfx_cmds->next;
	}
}