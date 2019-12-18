/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:42:13 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/18 17:43:26 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int_list	*ps_do_quicksort(t_int_list *a)
{
	int			p;
	int			count;
	int			i;
	t_int_list	*b;

	count = count_list(a);
	i = 0;
	b = NULL;
	while (i < count / 2)
	{
		b = add_front(b, extract_last(&a));
		i++;
	}
	p = get_last(a);
	ps_qsrt_swapper(&a, &b, p);
	print_list(a, "A @srt", ' ');
	print_list(b, "B @srt", ' ');
	if (a && !is_sort_list(a))
		a = ps_do_quicksort(a);
	if (b && !is_sort_list(b))
		b = ps_do_quicksort(b);
	print_list(a, "A @ret", ' ');
	print_list(b, "B @ret", ' ');
	return (ps_join_lsts(a, b));
}

void	ps_qsrt_swapper(t_int_list **a, t_int_list **b, int p)
{
	t_int_list	*pos_a;
	t_int_list	*pos_b;
	int			tmp;
	t_int_list	*tmp_node;

	pos_a = *a;
	pos_b = *b;
	while (pos_a->nb != p)
	{
		if (pos_a->nb > p)
		{
			while (pos_b)
			{
				if (pos_b->nb < p)
				{
					tmp = pos_b->nb;
					pos_b->nb = pos_a->nb;
					pos_a->nb = tmp;
					break ;
				}
				pos_b = pos_b->next;
			}
			if (!pos_b)
			{
				tmp_node = extract_nb(a, pos_a->nb);
				*b = add_back(*b, tmp_node);
				pos_a = *a;
			}
		}
		else
			pos_a = pos_a->next;
	}
	pos_b = *b;
	while (pos_b)
	{
		if (pos_b->nb < p)
		{
			tmp_node = extract_nb(b, pos_b->nb);
			*a = add_front(*a, tmp_node);
			pos_b = *b;
		}
		else
			pos_b = pos_b->next;
	}
}

