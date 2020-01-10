/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfx_draw_playback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:45:50 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/10 09:43:46 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vfx_push_swap.h"

void	vfx_draw_play_2(t_ps_vfx *vfx, t_point *p)
{
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x, p->y + 3 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + VFX_TXT_S,\
		p->y + 3 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_COVER, p->x + 2 * VFX_TXT_S,\
		p->y + 3 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x, p->y + 4 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_COVER, p->x + VFX_TXT_S,\
		p->y + 4 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_COVER, p->x + 2 * VFX_TXT_S,\
		p->y + 4 * VFX_TXT_S);
}

void	vfx_draw_play(t_ps_vfx *vfx)
{
	t_point p;

	p.x = WIN_WIDTH / 2 - VFX_TXT_S - VFX_TXT_S / 2;
	p.y = WIN_HEIGHT - (FOOT_BG_H / 4) * 3;
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p.x, p.y);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_COVER, p.x + VFX_TXT_S, p.y);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_COVER, p.x + 2 * VFX_TXT_S, p.y);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p.x, p.y + VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p.x + VFX_TXT_S, p.y +\
		VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_COVER, p.x + 2 * VFX_TXT_S,\
		p.y + VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p.x, p.y + 2 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p.x + VFX_TXT_S,\
		p.y + 2 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p.x + 2 * VFX_TXT_S,\
		p.y + 2 * VFX_TXT_S);
	vfx_draw_play_2(vfx, &p);
}

void	vfx_draw_pause_2(t_ps_vfx *vfx, t_point *p)
{
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x, p->y + 3 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_COVER, p->x + VFX_TXT_S,\
		p->y + 3 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + 2 * VFX_TXT_S,\
		p->y + 3 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x, p->y + 4 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_COVER, p->x + VFX_TXT_S,\
		p->y + 4 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + 2 * VFX_TXT_S,\
		p->y + 4 * VFX_TXT_S);
}

void	vfx_draw_pause(t_ps_vfx *vfx)
{
	t_point p;

	p.x = WIN_WIDTH / 2 - VFX_TXT_S - VFX_TXT_S / 2;
	p.y = WIN_HEIGHT - (FOOT_BG_H / 4) * 3;
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p.x, p.y);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_COVER, p.x + VFX_TXT_S, p.y);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p.x + 2 * VFX_TXT_S, p.y);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p.x, p.y + VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_COVER, p.x + VFX_TXT_S, p.y +\
		VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p.x + 2 * VFX_TXT_S,\
		p.y + VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p.x, p.y + 2 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_COVER, p.x + VFX_TXT_S,\
		p.y + 2 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p.x + 2 * VFX_TXT_S,\
		p.y + 2 * VFX_TXT_S);
	vfx_draw_pause_2(vfx, &p);
}
