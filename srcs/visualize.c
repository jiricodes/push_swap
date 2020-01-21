/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:51:52 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/21 15:23:26 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	visualise_ps(t_ps *ps)
{
	if (count_list(ps->org) > 900)
		error_exit("Over visualiser limit (900). Use the python version :)");
	ps->vfx = (t_ps_vfx*)malloc(sizeof(t_ps_vfx));
	ps->VFX_P = mlx_init();
	vfx_init(ps, ps->vfx);
	ps->VFX_W = mlx_new_window(ps->VFX_P, ps->vfx->w, ps->vfx->h,\
		"Push Swap by jnovotny@student.hive.fi");
	vfx_draw_env(ps->vfx);
	mlx_hook(ps->VFX_W, 2, 0, ps_vfx_key_press, ps);
	mlx_hook(ps->VFX_W, 3, 0, ps_vfx_key_release, ps);
	mlx_hook(ps->VFX_W, 17, 0, ps_vfx_exit_press, ps);
	mlx_loop_hook(ps->VFX_P, vfx_do_pushswap, ps);
	mlx_loop(ps->VFX_P);
}

/*
** Key HOLD
*/

int		ps_vfx_key_press(int key, t_ps *ps)
{
	if (key == KEY_ARROW_RIGHT)
	{
		PAUSE = 1;
		vfx_graph_step(ps);
	}
	else if (key == KEY_ARROW_UP)
		ps->vfx_gc = color_value(ps->vfx_gc, VFX_WHITE, 0.05);
	else if (key == KEY_ARROW_DOWN)
		ps->vfx_gc = color_value(ps->vfx_gc, VFX_BLACK, 0.05);
	return (0);
}

void	vfx_show_legend(void)
{
	system("open man/legend.txt");
}

int		ps_vfx_key_release(int key, t_ps *ps)
{
	if (key == 53)
		exit(0);
	else if (key == KEY_L)
		vfx_show_legend();
	else if (key == KEY_C)
		CMD_LN = !CMD_LN ? 1 : 0;
	else if (key == KEY_SPC)
		PAUSE = PAUSE ? 0 : 1;
	else if (key == KEY_R)
		ps->vfx_gc = VFX_RED;
	else if (key == KEY_G)
		ps->vfx_gc = VFX_GREEN;
	else if (key == KEY_B)
		ps->vfx_gc = VFX_BLUE;
	else if (key == KEY_F1)
		ps->vfx_gc = FLG_C ? ps->flags.color : VFX_ORANGE;
	else if (key == KEY_F2)
	{
		PAUSE = 1;
		vfx_reset_graph(ps);
		vfx_graph_step(ps);
	}
	return (0);
}

int		ps_vfx_exit_press(void)
{
	exit(0);
}
