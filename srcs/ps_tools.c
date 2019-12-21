/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:55:45 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/21 19:24:29 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_smart_rotate(t_stk *s)
{
	int			i;
	t_int_list	*tmp;

	i = 0;
	tmp = s->lst;
	while (tmp)
	{
		if (tmp->next && tmp->nb > tmp->next->nb)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i == 0)
		return (0);
	else if (i > s->count / 2)
		return (-1);
	else
		return (1);
}

// void	insert_extreme_b(ps)
// {
	
// }

void	do_smartpush_b(t_ps *ps)
{
	int	p;

	if (B_CNT < 2)
	{
		do_pb(ps);
		return ;
	}
	// if (A_TOP < B_MIN || A_TOP > B_MAX)
	// {
	// 	insert_extreme_b(ps);
	// 	if (!is_rev_rot_sort(ps->b))
	// 	{
	// 		ft_printf("{RED}{B}ERROR @smartpush_b after extreme insertion!{EOC}\n");
	// 		print_list(B_LST, "b not_revrotsort", ' ');
	// 		exit(0);
	// 	}
	// 	return ;
	// }
	p = find_slot_rev_rotsort(B_LST, A_TOP, B_MAX, B_MIN);
	ft_printf("Slot position = %d for %d\n", p, A_TOP);
	if (p < B_CNT / 2)
	{
		while (p-- > 0)
			do_rb(ps);
	}
	else
		while (p++ < B_CNT)
			do_rrb(ps);
	do_pb(ps);
	if (!is_rev_rot_sort(ps->b))
	{
		ft_printf("{RED}{B}ERROR @smartpush_b!{EOC}\n");
		print_list(B_LST, "b not_revrotsort", ' ');
		exit(0);
	}
}