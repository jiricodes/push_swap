/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfx_draw_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:39:35 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/10 09:58:46 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vfx_letter_a(t_ps_vfx *vfx, t_point *p)
{
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + VFX_TXT_S, p->y);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + 2 * VFX_TXT_S,\
		p->y);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x, p->y + VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + 3 * VFX_TXT_S,
		p->y + VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x, p->y + 2 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + VFX_TXT_S,\
		p->y + 2 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + 2 * VFX_TXT_S,\
		p->y + 2 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + 3 * VFX_TXT_S,\
		p->y + 2 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x, p->y + 3 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + 3 * VFX_TXT_S,\
		p->y + 3 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x, p->y + 4 * VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + 3 * VFX_TXT_S,\
		p->y + 4 * VFX_TXT_S);
}

void	vfx_letter_b(t_ps_vfx *vfx, t_point *p)
{
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x, p->y);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + VFX_TXT_S, p->y);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + VFX_TXT_S * 2, p->y);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x, p->y + VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + 3 * VFX_TXT_S,\
		p->y + VFX_TXT_S);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x, p->y + VFX_TXT_S * 2);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + VFX_TXT_S,\
		p->y + VFX_TXT_S * 2);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + VFX_TXT_S * 2,\
		p->y + VFX_TXT_S * 2);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x, p->y + VFX_TXT_S * 3);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + VFX_TXT_S * 3,\
		p->y + VFX_TXT_S * 3);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x, p->y + VFX_TXT_S * 4);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + VFX_TXT_S,\
		p->y + VFX_TXT_S * 4);
	mlx_put_image_to_window(VFX_P, VFX_W, VFX_TEXT, p->x + VFX_TXT_S * 2,\
		p->y + VFX_TXT_S * 4);
}
