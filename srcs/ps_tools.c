/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:55:45 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 16:01:53 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Final rotation of sorted list into proper position (min at the top)
*/

void	ps_smart_rotate_a(t_ps *ps)
{
	int			i;

	i = find_nb_pos(A_LST, A_MIN);
	qs_rot_a(ps, i);
}

/*
** Rotate A to a specific index
*/

void	qs_rot_a(t_ps *ps, int i)
{
	if (i <= A_CNT / 2)
		do_ra_i(ps, i);
	else
		do_rra_i(ps, i);
}

/*
**	Returns median of first N numbers of the list
*/

int		qs_get_median_range(t_int_list *list, int n)
{
	t_int_list	*tmp;
	int			res;

	if (n == 0)
		return (0);
	tmp = NULL;
	while (list && n > 0)
	{
		tmp = create_back(tmp, list->nb);
		list = list->next;
		n--;
	}
	res = get_median(tmp);
	clear_list(&tmp);
	return (res);
}

/*
** Checks if next N numbers of the list are sorted
*/

int		ps_check_sort_n(t_int_list *list, int len)
{
	while (list && len > 1)
	{
		if (list->next && list->nb > list->next->nb)
			return (FALSE);
		list = list->next;
		len--;
	}
	return (TRUE);
}

/*
** Returns [i] number of the list
*/

int		ps_get_i_val(t_int_list *list, int i)
{
	while (i-- > 0)
		list = list->next;
	return (list->nb);
}
