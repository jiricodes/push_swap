/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:49:20 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 17:58:24 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_to_func(t_int_list **a, t_int_list **b, char *cmd)
{
	if (ft_strequ(cmd, "sa"))
		*a = swap_top2(*a);
	else if (ft_strequ(cmd, "sb"))
		*b = swap_top2(*b);
	else if (ft_strequ(cmd, "ss"))
	{
		*a = swap_top2(*a);
		*b = swap_top2(*b);
	}
	else if (ft_strequ(cmd, "pa"))
		push(a, b);
	else if (ft_strequ(cmd, "pb"))
		push(b, a);
	else if (ft_strequ(cmd, "ra"))
		*a = rotate(*a);
	else if (ft_strequ(cmd, "rb"))
		*b = rotate(*b);
	else
		cmd_to_func2(a, b, cmd);
}

void	cmd_to_func2(t_int_list **a, t_int_list **b, char *cmd)
{
	if (ft_strequ(cmd, "rr"))
	{
		*a = rotate(*a);
		*b = rotate(*b);
	}
	else if (ft_strequ(cmd, "rra"))
		*a = rev_rotate(*a);
	else if (ft_strequ(cmd, "rrb"))
		*b = rev_rotate(*b);
	else if (ft_strequ(cmd, "rrr"))
	{
		*a = rev_rotate(*a);
		*b = rev_rotate(*b);
	}
	else
		error_exit("Wrong Command!");
}

void	ps_checker(t_int_list **a, t_int_list **b, t_cmd *cmd)
{
	t_cmd *ptr;

	ptr = cmd;
	while (ptr)
	{
		cmd_to_func(a, b, ptr->abbr);
		ptr = ptr->next;
	}
	is_correct_ps(*a, *b);
	// ft_printf("Result:\n");
	// print_list(*a, "a", ' ');
	// print_list(*b, "b", ' ');
}
