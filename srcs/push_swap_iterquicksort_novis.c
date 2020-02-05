/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_iterquicksort.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:09:13 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 19:47:23 by jnovotny         ###   ########.fr       */
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

static void	qs_dorun(t_ps *ps, int left, int right, t_int_list **run)
{
	int			to_run;
	int			pos;

	to_run = A_CNT;
	while (!is_rot_sort(ps->a))
	{
		if (to_run < 4)
			left = qs_specruns(ps, to_run, left);
		else if (ps_check_sort_n(A_LST, to_run))
			left = ps_get_i_val(A_LST, to_run - 1);
		else
		{
			*run = create_front(*run, qs_split_range(ps, left, right, to_run));
			left = qs_merge(ps);
		}
		if (is_rot_sort(ps->a) || !*run)
			break ;
		ps_info(ps);
		pos = find_nb_pos(A_LST, left);
		pos = pos == A_CNT - 1 ? 0 : pos + 1;
		qs_rot_a(ps, pos);
		to_run = qs_nextrun(run);
		right = qs_get_median_range(A_LST, to_run);
	}
}

void		push_swap(t_ps *ps)
{
	t_int_list	*runs;
	int			left;
	int			right;

	ps_info(ps);
	if (A_CNT == 3)
		ps_a_sort3(ps);
	else if (A_CNT > 3)
	{
		runs = NULL;
		left = find_min(A_LST) - 1;
		right = get_median(A_LST);
		qs_dorun(ps, left, right, &runs);
	}
	ps_smart_rotate_a(ps);
	parse_cmds(&(CMD));
	print_cmd_list(CMD);
	if (FLG_T)
		ft_printf("Total: %d\n", count_cmd_list(CMD));
	clear_ps(ps);
	clear_list(&runs);
}
