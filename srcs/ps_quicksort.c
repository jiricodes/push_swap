/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:42:13 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/19 13:20:47 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int_list	*ps_do_quicksort(t_int_list *a, t_cmd **cmd, char stk)
{
	int			p;
	int			count;
	int			i;
	t_int_list	*b;
	char		*c;

	count = count_list(a);
	i = 0;
	b = NULL;
	c = ft_strnew(3);
	while (i < count / 2)
	{
		b = add_front(b, extract_last(&a)); // rra && pb
		c[0] = 'r';
		c[1] = 'r';
		c[2] = stk;
		*cmd = create_cmd_back(*cmd, c);
		// push(&b, &a); // p + !stk
		// c[0] = 'p';
		// c[1] = stk == 'a' ? 'b' : 'a';
		// *cmd = create_cmd_back(*cmd, c);
		i++;
	}
	p = a->nb;
	a = rotate(a); // ra || rb
	c[0] = 'r';
	c[1] = stk;
	ps_qsrt_swapper(&a, &b, cmd,p, stk);
	print_list(a, "A @srt", ' ');
	print_list(b, "B @srt", ' ');
	if (a && !is_sort_list(a))
		a = ps_do_quicksort(a, cmd, stk);
	if (b && !is_sort_list(b))
		b = ps_do_quicksort(b, cmd, stk == 'a' ? 'b' : 'a');
	print_list(a, "A @ret", ' ');
	print_list(b, "B @ret", ' ');
	count = count_list(b);
	while (count-- > 0)
	{
		c[0] = 'p';
		c[1] = stk == 'a' ? 'b' : 'a';
		*cmd = create_cmd_back(*cmd, c);
		c[0] = 'r';
		*cmd = create_cmd_back(*cmd, c);
	}
	free(c);
	return (ps_join_lsts(a, b));
}

void	ps_qsrt_swapper(t_int_list **a, t_int_list **b, t_cmd **cmd, int p, char stk)
{
	t_int_list	*pos_a;
	t_int_list	*pos_b;
	int			tmp;
	t_int_list	*tmp_node;
	int			nb;
	char		*c;

	pos_a = *a;
	pos_b = *b;
	c = ft_strnew(3);
	while (pos_a->nb != p)
	{
		if (pos_a->nb > p)
		{
			while (pos_b)
			{
				if (pos_b->nb < p)
				{
					tmp = pos_b->nb;
					pos_b->nb = pos_a->nb; // pb & rb & pa
					pos_a->nb = tmp;
					c[0] = 'p';
					c[1] = stk == 'a' ? 'b' : 'a';
					*cmd = create_cmd_back(*cmd, c);
					c[0] = 'r';
					*cmd = create_cmd_back(*cmd, c);
					c[0] = 'p';
					c[1] = stk;
					*cmd = create_cmd_back(*cmd, c);
					break ;
				}
				pos_b = pos_b->next; // rb (if last ra then rr else rb)
				c[0] = 'r';
				c[1] = stk == 'a' ? 'b' : 'a';
				*cmd = create_cmd_back(*cmd, c);
			}
			if (!pos_b)
			{
				nb = pos_a->nb;
				pos_a = pos_a->next;
				tmp_node = extract_nb(a, nb); //pb & rb
				*b = add_back(*b, tmp_node);
				c[0] = 'p';
				c[1] = stk == 'a' ? 'b' : 'a';
				*cmd = create_cmd_back(*cmd, c);
				c[0] = 'r';
				*cmd = create_cmd_back(*cmd, c);
			}
		}
		else
		{
			pos_a = pos_a->next; // if last rb then rr else ra
			c[0] = 'r';
			c[1] = stk;
			*cmd = create_cmd_back(*cmd, c);
		}
	}
	// pos_b = *b;
	while (pos_b)
	{
		if (pos_b->nb < p)
		{
			nb = pos_b->nb;
			pos_b = pos_b->next;
			tmp_node = extract_nb(b, nb); //pa
			*a = add_front(*a, tmp_node);
			c[0] = 'p';
			c[1] = stk;
			*cmd = create_cmd_back(*cmd, c);
			// pos_b = *b;
		}
		else
		{
			pos_b = pos_b->next; //rb
			c[0] = 'r';
			c[1] = stk == 'a' ? 'b' : 'a';
			*cmd = create_cmd_back(*cmd, c);
		}
	}
	free(c);
}

