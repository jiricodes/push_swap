/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_iterquicksort.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:09:13 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 15:06:33 by jnovotny         ###   ########.fr       */
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

static int	qs_specruns(t_ps *ps, int to_run, int left)
{
	if (to_run == 1)
		left = A_TOP;
	else if (to_run == 2)
	{
		if (A_TOP > A_2ND)
			do_sa(ps);
		left = A_2ND;
	}
	else if (to_run == 3)
		left = ps_sort_top3a(ps);
	return (left);
}

void	push_swap(t_ps *ps)
{
	t_int_list	*runs;
	int			left;
	int			right;
	int			to_run;
	int			pos;

	ps_info(ps);
	runs = NULL;
	left = find_min(A_LST) - 1;
	right = get_median(A_LST);
	to_run = A_CNT;
	while (!is_rot_sort(ps->a))
	{
		if (to_run < 4)
			left = qs_specruns(ps, to_run, left);
		else if (ps_check_sort_n(A_LST, to_run))
			left = ps_get_i_val(A_LST, to_run - 1);
		else
		{
			runs = create_front(runs, qs_split_range(ps, left, right, to_run));
			if (is_rot_sort(ps->a))
			{
				while (B_LST)
				{
					qs_rot_a(ps, find_slot_rotsort(A_LST, B_MAX, A_MAX, A_MIN));
					ps_merge_rotate_b(ps, find_nb_pos(B_LST, B_MAX));
					do_pa(ps);
					ps_info(ps);
				}
				break ;
			}
			left = qs_merge(ps, &runs);
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
		to_run = qs_nextrun(&runs);
		right = qs_get_median_range(A_LST, to_run);
	}
	ps_smart_rotate_a(ps);
	parse_cmds(&(CMD));
	print_cmd_list(CMD);
	if (FLG_T)
		ft_printf("Total: %d\n", count_cmd_list(CMD));
	if (FLG_V)
		visualise_ps(ps);
	clear_ps(ps);
	clear_list(&runs);
}
