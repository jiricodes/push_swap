/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:53:26 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/10 13:24:01 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_merge_rotate_a(t_ps *ps, int slot)
{
	int i;

	if (slot < A_CNT / 2)
	{
		i = 0;
		while (i < slot && A_TOP != A_MIN)
		{
			do_ra(ps);
			i++;
		}
		while (i < slot && A_TOP < B_MAX)
		{
			do_ra(ps);
			i++;
		}
	}
	else
	{
		i = A_CNT;
		while (i > slot)
		{
			do_rra(ps);
			i--;
		}
	}
}

static void	ps_merge_rotate_b(t_ps *ps, int pos)
{
	int i;

	if (pos < B_CNT / 2)
	{
		i = 0;
		while (i < pos)
		{
			do_rb(ps);
			i++;
		}
	}
	else
	{
		i = B_CNT;
		while (i > pos)
		{
			do_rrb(ps);
			i--;
		}
	}
}

int			find_merge_slot(t_ps *ps)
{
	int			i;
	t_int_list	*tmp;

	i = 0;
	tmp = A_LST;
	while (tmp && tmp->nb != A_MIN)
	{
		i++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp->next && tmp->nb > tmp->next->nb)
			break ;
		else if (!tmp->next)
		{
			if (A_LAST < A_TOP)
			{
				tmp = A_LST;
				i = 0;
			}
			else
				return (i);
		}
		else
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i < A_CNT ? i : 0);
}

void		ps_merge(t_ps *ps)
{
	int	slot;
	int pos;

	ps_info(ps);
	pos = find_nb_pos(B_LST, B_MAX);
	slot = find_merge_slot(ps);
	ps_merge_rotate_a(ps, slot);
	ps_merge_rotate_b(ps, pos);
	// print_list(A_LST, "A pre-merge", ' ');
	// print_list(B_LST, "B pre-merge", ' ');
	while (B_LST)
	{
		if (A_LAST < A_TOP && A_LAST > B_TOP)
			do_rra(ps);
		else
			do_pa(ps);
	}
}
