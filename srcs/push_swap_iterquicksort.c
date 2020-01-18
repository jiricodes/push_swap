/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_iterquicksort.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:09:13 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/17 19:57:39 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Iterative quicksort version of Push_Swap
** The algorithm works with Runs which are determined by minimum value (left)
**	of the segment and the median (right). So for every n that
** left < n <= right it pushes to other stack. And repeats the process
** until sorted. Initially the algorithm should work as simply as that,
** however to meet certain benchmarks, it had to optimized.
** So if at any point a current segment or run on stack B is < 16 numbers long.
** It should be inserted to stack A in sorted manner.
** There is special case for stack of 3 numbers (simplest sort solution)
**
** Operations per size of stack goals:
**		5 nbs	under   12 ops
**	  100 nbs	under  700 ops
**	  500 nbs	under 5500 ops
*/

void	push_swap(t_ps *ps)
{
	t_int_list *runs;
	int	left;
	int right;
	// int current;
	int	to_run;
	int pos;
	// char s[1];

	ps_info(ps);
	runs = NULL;
	left = find_min(A_LST) - 1;
	right = get_median(A_LST);
	// current = qs_runlenght(A_LST, left, right);
	to_run = A_CNT;
	while (!is_rot_sort(ps->a))
	{
		// ft_printf("Presplit: %d | %d | %d\n", left, right, to_run);
		// ft_printf("First %d | Last %d\n", A_TOP, A_LAST);
		// read(0, s, 1);
		// print_cmd_list(CMD);
		if (to_run == 0)
		{
			// ft_printf("Dick\n");
		}
		else if (to_run == 1)
			left = A_TOP;
		else if (to_run == 2)
		{
			if (A_TOP > A_2ND)
				do_sa(ps);
			left = A_2ND;
		}
		else if (to_run == 3)
			left = ps_sort_top3a(ps);
		else
		{
			//check if already sorted
			if (ps_check_sort_n(A_LST, to_run))
				left = ps_get_i_val(A_LST, to_run - 1);
			else
			{
			//check if sa
			//check if oneoff
				runs = create_front(runs, qs_split_range(ps, left, right, to_run));
				if (is_rot_sort(ps->a))
				{
					while (B_LST)
					{
						// this needs a optimization
						// ft_printf("B_MAX %d | SLOT i %d\n", B_MAX, find_slot_rotsort(A_LST, B_MAX, A_MAX, A_MIN));
						// print_list(A_LST, "A", ' ');
						// print_list(B_LST, "B", ' ');
						// print_cmd_list(CMD);
						qs_rot_a(ps, find_slot_rotsort(A_LST, B_MAX, A_MAX, A_MIN));
						ps_merge_rotate_b(ps, find_nb_pos(B_LST, B_MAX));
						do_pa(ps);
						ps_info(ps);
					}
					break;
				}
				left = qs_merge(ps, &runs);
			}
		}
		if (is_rot_sort(ps->a) || !runs)
			break ;
		ps_info(ps);
		pos = find_nb_pos(A_LST, left);
		if (pos == A_CNT - 1)
			pos = 0;
		else
			pos++;
		qs_rot_a(ps, pos);
		// print_list(runs, "runs", ' ');
		to_run = qs_nextrun(&runs);
		right = qs_get_median_range(A_LST, to_run);
		// print_list(runs, "runs", ' ');
		// ft_printf("%d\n", to_run);
		// print_cmd_list(CMD);
		
		
	// 	// special cases (to_run < 4)
	// 	//split
	// 	//merge
	// 	// left = merge()
	// 	to_run = qs_nextrun(&runs);
	// 	// right = median from next run
	// 	// measure run and update runs_list

	}
	ps_smart_rotate_a(ps);
	parse_cmds(&(CMD));
	print_cmd_list(CMD);
	if (FLG_T)
		ft_printf("Total: %d\n", count_cmd_list(CMD));
	// if (FLG_V)
	// 	visualise_ps(ps);
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
	push(&(B_LST), &(A_LST));
	CMD = create_cmd_back(CMD, "pb");
	ps_info(ps);
}

void	do_pa(t_ps *ps)
{
	push(&(A_LST), &(B_LST));
	CMD = create_cmd_back(CMD, "pa");
	ps_info(ps);
}

void	do_sa(t_ps *ps)
{
	A_LST = swap_top2(A_LST);
	CMD = create_cmd_back(CMD, "sa");
}

void	do_sb(t_ps *ps)
{
	B_LST = swap_top2(B_LST);
	CMD = create_cmd_back(CMD, "sb");
}

void	do_ra(t_ps *ps)
{
	A_LST = rotate(A_LST);
	CMD = create_cmd_back(CMD, "ra");
}

void	do_rb(t_ps *ps)
{
	B_LST = rotate(B_LST);
	CMD = create_cmd_back(CMD, "rb");
}

void	do_rra(t_ps *ps)
{
	A_LST = rev_rotate(A_LST);
	CMD = create_cmd_back(CMD, "rra");
}

void	do_rrb(t_ps *ps)
{
	B_LST = rev_rotate(B_LST);
	CMD = create_cmd_back(CMD, "rrb");
}
