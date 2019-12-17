/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfx_draw_graph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:53:30 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/17 16:08:30 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	vfx_do_pushswap(t_ps *ps)
{
	if (!PAUSE)
		vfx_graph_step(ps);
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
	mlx_put_image_to_window(ps->VFX_P, ps->VFX_W, ps->vfx->graph_bg.img, BORDER, HDR_BG_H);
	p.x = BORDER;
	p.y = HDR_BG_H + ps->vfx->graph_bg.height - 1;
	ft_printf("start of graph: %d x %d\n", p.x, p.y);
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
	mlx_put_image_to_window(ps->VFX_P, ps->VFX_W, ps->vfx->graph_bg.img, BORDER +\
		ps->vfx->graph_bg.width + 2, HDR_BG_H);
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

void	vfx_draw_cmds(t_ps *ps)
{
	t_cmd *tmp;
	int		i;

	tmp = ps->vfx_cmds;
	mlx_put_image_to_window(ps->VFX_P, ps->VFX_W, ps->vfx->hdr_img.img,\
			0, HDR_BG_H - ps->vfx->hdr_img.height - 1);
	if (CMD_LN)
	{
		mlx_string_put(ps->VFX_P, ps->VFX_W, 10, 50, VFX_BLACK, "COMMANDS: ");
		mlx_string_put(ps->VFX_P, ps->VFX_W, 115, 50, VFX_D_GRAY, ps->vfx->last_cmd);
		if (tmp)
		{
			mlx_string_put(ps->VFX_P, ps->VFX_W, 165, 50, VFX_GREEN, tmp->abbr);
			tmp = tmp->next;
		}
		i = 1;
		while (tmp && 165 + i * 50 < WIN_WIDTH - 30)
		{
			mlx_string_put(ps->VFX_P, ps->VFX_W, 165 + i * 50, 50, VFX_D_GRAY, tmp->abbr);
			tmp = tmp->next;
			i++;
		}
	}
	if (ps->vfx_cmds)
	{
		ft_strdel(&(ps->vfx->last_cmd));
		ps->vfx->last_cmd = ft_strdup(ps->vfx_cmds->abbr);
	}
}
