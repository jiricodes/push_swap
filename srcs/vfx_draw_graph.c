/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfx_draw_graph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:53:30 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/10 09:55:41 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		vfx_do_pushswap(t_ps *ps)
{
	if (!PAUSE)
	{
		vfx_draw_play(ps->vfx);
		vfx_graph_step(ps);
	}
	else
		vfx_draw_pause(ps->vfx);
	return (0);
}

void	vfx_graph_step(t_ps *ps)
{
	if (!ps->vfx_cmds)
		return ;
	cmd_to_func(&(ps->vfx_a->lst), &(ps->vfx_b->lst), ps->vfx_cmds->abbr);
	vfx_draw_cmds(ps);
	ps->vfx_cmds = ps->vfx_cmds->next;
	vfx_draw_graph_a(ps);
	vfx_draw_graph_b(ps);
}

void	vfx_draw_graph_a(t_ps *ps)
{
	int			i;
	int			j;
	t_point		p;
	t_int_list	*tmp;

	tmp = ps->vfx_a->lst;
	mlx_put_image_to_window(ps->VFX_P, ps->VFX_W, ps->vfx->graph_bg.img,\
		BORDER, HDR_BG_H);
	p.x = BORDER;
	p.y = HDR_BG_H + ps->vfx->graph_bg.height - 1;
	i = 0;
	while (tmp)
	{
		j = -1;
		while (++j < tmp->nb * ps->vfx->rat)
			mlx_pixel_put(ps->VFX_P, ps->VFX_W, p.x + j, p.y - i, ps->vfx_gc);
		if (i % ps->vfx->lines == 0 && i != 0)
			tmp = tmp->next;
		i++;
	}
}

void	vfx_draw_graph_b(t_ps *ps)
{
	int			i;
	int			j;
	t_point		p;
	t_int_list	*tmp;

	tmp = ps->vfx_b->lst;
	mlx_put_image_to_window(ps->VFX_P, ps->VFX_W, ps->vfx->graph_bg.img,\
		BORDER + ps->vfx->graph_bg.width + 2, HDR_BG_H);
	p.x = BORDER + ps->vfx->graph_bg.width + 2;
	p.y = HDR_BG_H + ps->vfx->graph_bg.height - 1;
	i = 0;
	while (tmp)
	{
		j = -1;
		while (++j < tmp->nb * ps->vfx->rat)
			mlx_pixel_put(ps->VFX_P, ps->VFX_W, p.x + j, p.y - i, ps->vfx_gc);
		if (i % ps->vfx->lines == 0 && i != 0)
			tmp = tmp->next;
		i++;
	}
}
