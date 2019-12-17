/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfx_environment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:02:09 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/17 16:07:23 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vfx_init(t_ps *ps, t_ps_vfx *vfx)
{
	vfx->w = WIN_WIDTH;
	vfx->h = WIN_HEIGHT;
	vfx_init_elems(vfx);
	vfx_copy_info(ps);
	vfx->rat = (vfx->graph_bg.width - 2) / ps->max;
	vfx->lines = (vfx->graph_bg.height - 2) / ps->count;
	if (vfx->lines > 20)
		vfx->lines = 20;
	ps->vfx_gc = FLG_C ? ps->flags.color : VFX_ORANGE;
	PAUSE = 1;
	CMD_LN = 1;
	ps->vfx->last_cmd = ft_strnew(1);
}

void	vfx_init_elems(t_ps_vfx *vfx)
{
	vfx->bg_img.width = WIN_WIDTH;
	vfx->bg_img.height = WIN_HEIGHT;
	vfx->bg_img.color = VFX_L_BLUE;
	vfx_create_rectangle_img(VFX_P, &(vfx->bg_img));
	vfx->hdr_img.width = WIN_WIDTH;
	vfx->hdr_img.height = 30;
	vfx->hdr_img.color = VFX_L_BLUE;
	vfx_create_rectangle_img(VFX_P, &(vfx->hdr_img));
	vfx->graph_bg.width = WIN_WIDTH / 2 - BORDER - 1;
	vfx->graph_bg.height = WIN_HEIGHT - HDR_BG_H - FOOT_BG_H;
	vfx->graph_bg.color = VFX_BLACK;
	vfx_create_rectangle_img(VFX_P, &(vfx->graph_bg));
	vfx->text_tile.width = 5;
	vfx->text_tile.height = 5;
	vfx->text_tile.color = VFX_BLACK;
	vfx_create_rectangle_img(VFX_P, &(vfx->text_tile));
}

void	vfx_copy_info(t_ps *ps)
{
	ps->vfx_a = (t_stk *)malloc(sizeof(t_stk));
	ps->vfx_a->count = ps->count;
	ps->vfx_a->min = ps->min;
	ps->vfx_a->max = ps->max;
	ps->vfx_a->lst = ps->org;
	ps->vfx_b = (t_stk *)malloc(sizeof(t_stk));
	ft_bzero(ps->vfx_b, sizeof(t_stk));
	ps->vfx_cmds = ps->cmds;
}