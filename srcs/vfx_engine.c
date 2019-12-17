/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfx_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:59:03 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/17 11:28:31 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vfx_create_rectangle_img(void *mlx_ptr, t_vfx_img *elem)
{
	int		i;

	elem->img = mlx_new_image(mlx_ptr, elem->width, elem->height);
	elem->img_p = mlx_get_data_addr(elem->img, &(elem->bpp),\
		&(elem->line_s), &(elem->endian));
	i = 0;
	while (i < elem->width * elem->height)
	{
		*(int *)(elem->img_p + (int)(i * (elem->bpp / 8))) = elem->color;
		i++;
	}
}
