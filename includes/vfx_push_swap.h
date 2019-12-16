/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfx_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:53:42 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/16 12:59:48 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VFX_PUSH_SWAP_H
# define VFX_PUSH_SWAP_H

# include "mlx.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

typedef struct	s_ps_vfx
{
	void	*mlx_p;
	void	*win_p;
	int		w;
	int		h;
	int		rat;
}				t_ps_vfx;
#endif