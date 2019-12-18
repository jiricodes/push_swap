/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:51:52 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/18 15:35:59 by jnovotny         ###   ########.fr       */
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
	mlx_hook(ps->VFX_W, 3, 0, ps_vfx_key_release, ps);
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
	{
		if (ps->vfx_gc <= VFX_WHITE - 100)
			ps->vfx_gc += 100;
	}
	else if (key == KEY_ARROW_DOWN)
	{
		if (ps->vfx_gc >= 100)
			ps->vfx_gc -= 100;
	}
	return (0);
}

void	vfx_show_legend(void)
{
	// vfx->legend_w = mlx_new_window(VFX_P, 200, 1080, "Push_Swap Legend");
	system("open man/legend.txt");
}

int		ps_vfx_key_release(int key, t_ps *ps)
{
	if (key == 53)
	{
		ft_bzero(ps->vfx, sizeof(t_ps_vfx));
		exit(0);
	}
	else if (key == KEY_L)
		vfx_show_legend();
	else if (key == KEY_C)
		CMD_LN = !CMD_LN ? 1 : 0;
	else if (key == KEY_SPC)
		PAUSE = PAUSE ? 0 : 1;
	else
		ft_printf("Pressed key_id %d\n", key);
	return (0);
}