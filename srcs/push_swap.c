/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:09:13 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/17 11:05:11 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_ps *ps)
{
	int i;
	int pos;

	ps_info(ps);
	i = 0;
	pos = 0;
	while (!(is_rot_sort(ps->a) && B_LST == NULL) && i < 100)
	{
		ft_printf("i = %d: ", i);
		if (A_TOP > A_2ND && A_CNT > B_CNT)
		{
			if (B_LST && A_TOP < B_TOP && A_TOP > B_MIN)
				while (A_TOP < B_TOP)
					do_rb(ps);
			else if (B_CNT > 1 && A_TOP > B_LAST && A_TOP < B_MAX)
				while (A_TOP > B_LAST)
					do_rrb(ps);
			do_pb(ps);
		}
		else if (B_LST && B_TOP > A_LAST && B_TOP < A_TOP)
			do_pa(ps);
		else if (A_TOP > A_2ND)
			do_sa(ps);
		else if (B_CNT > 1 && B_TOP < B_2ND)
			do_sb(ps);
		else if ((A_TOP < A_2ND && A_TOP > A_LAST) || A_TOP == A_MIN)
			do_ra(ps);
		else if (A_TOP < A_2ND && A_TOP < A_LAST)
			do_rra(ps);
		if (is_rot_sort(ps->a))
		{
			if (find_nb_pos(B_LST, B_MAX) < B_CNT / 2)
				while (B_TOP != B_MAX)
					do_rb(ps);
			else
				while (B_TOP != B_MAX)
					do_rrb(ps);
			print_list(A_LST, "a @rot_sort", ' ');
			print_list(B_LST, "b @a_rot_sort", ' ');
			while (B_LST)
			{
				if ((B_TOP > A_LAST && B_TOP < A_TOP) || (B_TOP > A_MAX && A_LAST == A_MAX))
					do_pa(ps);
				else if (find_slot_rotsort(A_LST, B_TOP, A_MAX) < (A_CNT / 2))
					do_ra(ps);
				else
					do_rra(ps);
				print_list(A_LST, "a @zip", ' ');
				print_list(B_LST, "b @zip", ' ');
			}
		}
		print_list(A_LST, "a @ps", ' ');
		print_list(B_LST, "b @ps", ' ');
		i++;
	}
	ft_printf("Loop stopped after %d iterations:\n", i);
	ft_printf("ps: cnt = %d, min = %d, max = %d\n", ps->count, ps->min, ps->max);
	pos = is_rot_sort(ps->a);
	ft_printf("pos = %d\n", pos);
	if (pos <= ps->count / 2)
	{
		while (pos-- > 0)
			do_ra(ps);
	}
	else
	{
		while (pos++ <= ps->count)
			do_rra(ps);
	}
	print_cmd_list(CMD);
	if (FLG_T)
		ft_printf("Total: %d\n", count_cmd_list(CMD));
	print_list(A_LST, "a @ps end", ' ');
	print_list(B_LST, "b @ps end", ' ');
	if (FLG_V)
		visualise_ps(ps);
	clear_ps(ps);
}

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

void	do_pb(t_ps *ps)
{
	ft_printf("@do_pb\n");
	push(&(B_LST), &(A_LST));
	CMD = create_cmd_back(CMD, "pb");
	ps_info(ps);
}

void	do_pa(t_ps *ps)
{
	ft_printf("@do_pa\n");
	push(&(A_LST), &(B_LST));
	CMD = create_cmd_back(CMD, "pa");
	ps_info(ps);
}

void	do_sa(t_ps *ps)
{
	ft_printf("@do_sa\n");
	A_LST = swap_top2(A_LST);
	CMD = create_cmd_back(CMD, "sa");
}

void	do_sb(t_ps *ps)
{
	ft_printf("@do_sb\n");
	B_LST = swap_top2(B_LST);
	CMD = create_cmd_back(CMD, "sb");
}

void	do_ra(t_ps *ps)
{
	ft_printf("@do_ra\n");
	A_LST = rotate(A_LST);
	CMD = create_cmd_back(CMD, "ra");
}

void	do_rb(t_ps *ps)
{
	ft_printf("@do_rb\n");
	B_LST = rotate(B_LST);
	CMD = create_cmd_back(CMD, "rb");
}

void	do_rra(t_ps *ps)
{
	ft_printf("@do_rra\n");
	A_LST = rev_rotate(A_LST);
	CMD = create_cmd_back(CMD, "rra");
}

void	do_rrb(t_ps *ps)
{
	ft_printf("@do_rrb\n");
	B_LST = rev_rotate(B_LST);
	CMD = create_cmd_back(CMD, "rrb");
}
