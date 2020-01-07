/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfx_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:53:42 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/07 14:54:29 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VFX_PUSH_SWAP_H
# define VFX_PUSH_SWAP_H

# include "mlx.h"
# include "vfx_colors.h"
# include "key_codes.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define HDR_BG_H 80
# define FOOT_BG_H 80
# define BORDER 10
# define VFX_P vfx->mlx_p
# define VFX_W vfx->win_p
# define VFX_TEXT vfx->text_tile.img
# define VFX_COVER vfx->cover_tile.img
# define VFX_TXT_S vfx->text_tile.width
# define PAUSE ps->vfx->pause
# define CMD_LN ps->vfx->cmd_line

/*
** Point coordinates struct
*/

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;
/*
** Graphic Element Struct
*/

typedef struct	s_vfx_img
{
	int		width;
	int		height;
	int		color;
	void	*img;
	char	*img_p;
	int		bpp;
	int		line_s;
	int		endian;
}				t_vfx_img;

typedef struct	s_ps_vfx
{
	void		*mlx_p;
	void		*win_p;
	int			w;
	int			h;
	int			rat;
	int			lines;
	t_vfx_img	hdr_img;
	t_vfx_img	bg_img;
	t_vfx_img	graph_bg;
	t_vfx_img	text_tile;
	t_vfx_img	cover_tile;
	void		*legend_w;
	int			cmd_line;
	int			pause;
	char		*last_cmd;
}				t_ps_vfx;

/*
** Image generators
*/

void	vfx_create_rectangle_img(void *mlx_ptr, t_vfx_img *elem);

/*
** Drawing & Image placing functions
*/

void	vfx_draw_env(t_ps_vfx *vfx);
void	vfx_text_img(t_ps_vfx *vfx);
void	vfx_letter_a(t_ps_vfx *vfx, t_point *p);
void	vfx_letter_b(t_ps_vfx *vfx, t_point *p);
void	vfx_draw_play(t_ps_vfx *vfx);
void	vfx_draw_pause(t_ps_vfx *vfx);

/*
** Event managememt
*/

void	vfx_show_legend(void);

#endif