/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:28:51 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 14:36:25 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ps(t_ps *ps)
{
	ft_bzero(ps, sizeof(t_ps));
	ps->org = NULL;
	ps->a = (t_stk*)malloc(sizeof(t_stk));
	ft_bzero(ps->a, sizeof(t_stk));
	ps->a->lst = NULL;
	ps->b = (t_stk*)malloc(sizeof(t_stk));
	ft_bzero(ps->b, sizeof(t_stk));
	ps->b->lst = NULL;
	ps->cmds = NULL;
}

void	ps_info(t_ps *ps)
{
	ps->count = count_list(ps->a->lst);
	ps->min = find_min(ps->a->lst);
	ps->max = find_max(ps->a->lst);
	ps->a->count = count_list(ps->a->lst);
	ps->a->min = find_min(ps->a->lst);
	ps->a->max = find_max(ps->a->lst);
	ps->b->count = count_list(ps->b->lst);
	ps->b->min = find_min(ps->b->lst);
	ps->b->max = find_max(ps->b->lst);
}
