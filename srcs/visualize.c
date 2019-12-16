/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:51:52 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/16 15:31:38 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	visualise_ps(t_ps *ps)
{
	t_ps_vfx vfx;

	vfx.mlx_p = mlx_init();
	vfx.win_p = mlx_new_window(vfx.mlx_p, vfx.w, vfx.h, "Push Swap");
	mlx_hook(vfx.win_p, 2, 0, psvfx_key_press, ps);
	mlx_loop_hook(vfx.mlx_p, do_push_swap, ps);
	mlx_loop(vfx.mlx_p);
}

int	psvfx_key_press(int key, t_ps *ps)
{
	
}