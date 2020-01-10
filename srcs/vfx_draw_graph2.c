/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfx_draw_graph2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:53:30 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/10 09:58:02 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_cmds(t_ps *ps, t_cmd *tmp)
{
	int		i;

	if (CMD_LN)
	{
		mlx_string_put(ps->VFX_P, ps->VFX_W, 10, 50, VFX_BLACK, "COMMANDS: ");
		mlx_string_put(ps->VFX_P, ps->VFX_W, 115, 50,\
			VFX_D_GRAY, ps->vfx->last_cmd);
		if (tmp)
		{
			mlx_string_put(ps->VFX_P, ps->VFX_W, 165, 50, VFX_GREEN, tmp->abbr);
			tmp = tmp->next;
		}
		i = 1;
		while (tmp && 165 + i * 50 < WIN_WIDTH - 30)
		{
			mlx_string_put(ps->VFX_P, ps->VFX_W,\
				165 + i * 50, 50, VFX_D_GRAY, tmp->abbr);
			tmp = tmp->next;
			i++;
		}
	}
}

void		vfx_draw_cmds(t_ps *ps)
{
	t_cmd *tmp;

	tmp = ps->vfx_cmds;
	mlx_put_image_to_window(ps->VFX_P, ps->VFX_W, ps->vfx->hdr_img.img,\
			0, HDR_BG_H - ps->vfx->hdr_img.height - 1);
	put_cmds(ps, tmp);
	if (ps->vfx_cmds)
	{
		ft_strdel(&(ps->vfx->last_cmd));
		ps->vfx->last_cmd = ft_strdup(ps->vfx_cmds->abbr);
	}
}
