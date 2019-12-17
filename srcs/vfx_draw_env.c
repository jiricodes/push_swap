/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfx_draw_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:25:08 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/17 12:32:22 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vfx_draw_env(t_ps_vfx *vfx)
{
	mlx_put_image_to_window(VFX_P, VFX_W, vfx->bg_img.img, 0, 0);
	mlx_string_put(VFX_P, VFX_W, WIN_WIDTH / 2 - 45, 20, VFX_BLACK,\
		"PUSH_SWAP");
	mlx_put_image_to_window(VFX_P, VFX_W, vfx->graph_bg.img, BOARDER, HDR_BG_H);
	mlx_put_image_to_window(VFX_P, VFX_W, vfx->graph_bg.img, BOARDER +\
		vfx->graph_bg.width + 2, HDR_BG_H);
	vfx_text_img(vfx);
	mlx_string_put(VFX_P, VFX_W, 10, WIN_HEIGHT - 20, 0, "(ESC) EXIT");
	mlx_string_put(VFX_P, VFX_W, 210, WIN_HEIGHT - 20, 0, "(L) LEGEND");
}

void	vfx_text_img(t_ps_vfx *vfx)
{
	t_point p;

	p.x = WIN_WIDTH / 4;
	p.y = WIN_HEIGHT - (FOOT_BG_H / 4) * 3;
	vfx_letter_a(vfx, &p);
	p.x *= 3;
	vfx_letter_b(vfx, &p);
}
