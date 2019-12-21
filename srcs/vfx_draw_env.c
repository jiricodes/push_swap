/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfx_draw_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:25:08 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/21 16:13:30 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vfx_draw_env(t_ps_vfx *vfx)
{
	mlx_put_image_to_window(VFX_P, VFX_W, vfx->bg_img.img, 0, 0);
	mlx_string_put(VFX_P, VFX_W, WIN_WIDTH / 2 - 45, 20, VFX_BLACK,\
		"PUSH_SWAP");
	mlx_put_image_to_window(VFX_P, VFX_W, vfx->graph_bg.img, BORDER, HDR_BG_H);
	mlx_put_image_to_window(VFX_P, VFX_W, vfx->graph_bg.img, BORDER +\
		vfx->graph_bg.width + 2, HDR_BG_H);
	vfx_text_img(vfx);
	mlx_string_put(VFX_P, VFX_W, 10, WIN_HEIGHT - 20, 0, "(ESC) EXIT");
	mlx_string_put(VFX_P, VFX_W, 210, WIN_HEIGHT - 20, 0, "(L) LEGEND");
	mlx_string_put(VFX_P, VFX_W, 410, WIN_HEIGHT - 20, 0, "(SPC) PLAY/PAUSE");
	mlx_string_put(VFX_P, VFX_W, 610, WIN_HEIGHT - 20, 0, "(->) NEXT CMD");
	mlx_string_put(VFX_P, VFX_W, 810, WIN_HEIGHT - 20, 0, "(UP/DOWN) COLOR");
	mlx_string_put(VFX_P, VFX_W, 1010, WIN_HEIGHT - 20, 0, "(R,G,B) RGB");
	mlx_string_put(VFX_P, VFX_W, 1210, WIN_HEIGHT - 20, 0, "(C) COMMANDS");
	mlx_string_put(VFX_P, VFX_W, 1410, WIN_HEIGHT - 20, 0, "(F1) RESET COLOR");
	mlx_string_put(VFX_P, VFX_W, 1610, WIN_HEIGHT - 20, 0, "(F2) RESET GRAPH");
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
