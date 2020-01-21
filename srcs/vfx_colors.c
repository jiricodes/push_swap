/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfx_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:30:36 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/21 14:55:40 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		c_grad(int start, int end, double per)
{
	return ((int)((1 - per) * start + per * end));
}

int				color_value(int current, int end, double per)
{
	int red;
	int green;
	int blue;

	if (current == end)
		return (current);
	red = c_grad((current >> 16) & 0xFF, (end >> 16) & 0xFF, per);
	green = c_grad((current >> 8) & 0xFF, (end >> 8) & 0xFF, per + 0.01);
	blue = c_grad(current & 0xFF, end & 0xFF, per + 0.02);
	return ((red << 16) | (green << 8) | blue);
}
