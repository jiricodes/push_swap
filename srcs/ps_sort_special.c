/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_special.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:53:23 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/13 12:33:27 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sorts specifically following problem of 3 numbers
** [1, 3, 2] [2, 1, 3] [3, 2, 1]
*/

void	sort_three(t_ps *ps)
{
	ps_info(ps);
	if (A_CNT == 3 && !is_rot_sort(ps->a))
		do_sa(ps);
	if (B_CNT == 3 && !is_rot_sort(ps->b))
		do_sb(ps);
}

/*
** Checks if Stack A has only one misplaced number
*/

void	check_one_out(t_ps *ps)
{
	t_int_list 	*test;
	int			i;

	if (A_CNT < 4)
		return ;
	test = copy_list(A_LST);
	i = find_unsort_index(ps);
	while (i > 0)
	{
		test = rotate(test);
		i--;
	}
	if (test->nb > test->next->nb && test->nb < test->next->next->nb)
	{
		test = swap_top2(test);
		if (is_rot_sort_list)
	}
}

/*
** Check whether a list is sorted, but rotated (min after max).
** Returns the position of min value.
*/
Fix this shit into working version!
int		is_rot_sort_list(t_int_list *lst)
{
	t_int_list	*tmp;
	int			i;
	int			res;

	i = 1;
	res = i;
	tmp = stack->lst;
	if (tmp && tmp->nb != stack->min && tmp->nb < get_last(tmp))
		return (0);
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
		{
			if (tmp->nb == stack->max && tmp->next->nb == stack->min)
			{
				res = i + 1;
				tmp = tmp->next;
				continue;
			}
			return (0);
		}
		tmp = tmp->next;
		i++;
	}
	return (res);
}