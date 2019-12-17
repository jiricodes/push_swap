/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 10:34:13 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/17 11:07:33 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks Whether the given list is sorted
*/

int		is_sort_list(t_int_list *list)
{
	while (list->next)
	{
		if (list->nb > list->next->nb)
			return (0);
		list = list->next;
	}
	return (1);
}

/*
** Checker binary output (a is sorted and b is null)
*/

void	is_correct_ps(t_int_list *a, t_int_list *b)
{
	if (is_sort_list(a) && b == NULL)
		ft_printf("{GREEN}{B}OK{EOC}\n");
	else
		ft_printf("{RED}{B}KO{EOC}\n");
}

/*
** Check whether a list is sorted, but rotated (min after max).
** Returns the position of min value.
*/

int		is_rot_sort(t_stk *stack)
{
	t_int_list	*tmp;
	int			position;
	int			i;

	position = 1;
	i = 1;
	tmp = stack->lst;
	ft_printf("@rot_sort: ");
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb && (tmp->nb != stack->max ||\
			tmp->next->nb != stack->min))
		{
			ft_printf("\n");
			return (0);
		}
		ft_printf("%d <= %d | ", tmp->nb, tmp->next->nb);
		if (tmp->nb == stack->min)
			position = i;
		else if (tmp->next->nb == stack->min)
			position = i + 1;
		tmp = tmp->next;
		i++;
	}
	ft_printf("\n");
	return (position);
}

/*
** Returns position where a given number could be placed in a sorted list.
** In unsorted list the return value is the first valid position.
*/

int		find_slot(t_int_list *list, int nb)
{
	int		pos;

	pos = 1;
	while (list && nb > list->nb)
	{
		pos++;
		list = list->next;
	}
	return (pos);
}
