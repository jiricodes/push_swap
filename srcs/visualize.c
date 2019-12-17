/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:51:52 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/17 12:43:05 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	visualise_ps(t_ps *ps)
{
	ps->vfx = (t_ps_vfx*)malloc(sizeof(t_ps_vfx));
	ps->VFX_P = mlx_init();
	vfx_init(ps, ps->vfx);
	ps->VFX_W = mlx_new_window(ps->VFX_P, ps->vfx->w, ps->vfx->h,\
		"Push Swap by jnovotny@student.hive.fi");
	vfx_draw_env(ps->vfx);
	mlx_hook(ps->VFX_W, 2, 0, ps_vfx_key_press, ps);
	// mlx_loop_hook(vfx.mlx_p, do_push_swap, ps);
	mlx_loop(ps->VFX_P);
}

int		ps_vfx_key_press(int key, t_ps *ps)
{
	if (key == 53)
	{
		ft_bzero(ps->vfx, sizeof(t_ps_vfx));
		exit(0);
	}
	else if (key == KEY_L)
		vfx_show_legend();
	else if (key == KEY_C)
		ps->vfx->cmd_line = ps->vfx->cmd_line == 0 ? 1 : 0;
	else
	{
		ft_printf("Pressed key_id %d\n", key);
	}
	return (0);
}

void	vfx_show_legend(void)
{
	// vfx->legend_w = mlx_new_window(VFX_P, 200, 1080, "Push_Swap Legend");
	system("open man/legend.txt");
}
