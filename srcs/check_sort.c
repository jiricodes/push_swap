/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 10:34:13 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/14 10:49:34 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	is_correct_ps(t_int_list *a, t_int_list *b)
{
	if (is_sort_list(a) && b == NULL)
		ft_printf("{GREEN}{B}OK{EOC}\n");
	else
		ft_printf("{RED}{B}KO{EOC}\n");
}
