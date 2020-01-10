/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:11:57 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/10 09:59:57 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		find_ra(t_cmd **cmd)
{
	t_cmd *tmp;

	tmp = *cmd;
	if (tmp->next && ft_strequ(tmp->next->abbr, "rb"))
		find_ra(&(tmp->next));
	while (tmp->next && ft_strequ(tmp->next->abbr, "rr"))
		tmp = tmp->next;
	if (tmp->next && ft_strequ(tmp->next->abbr, "ra"))
	{
		free((*cmd)->abbr);
		(*cmd)->abbr = ft_strdup("rr");
		remove_cmd(&tmp);
	}
}

void		parse_rb(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		if (ft_strequ(tmp->abbr, "rb"))
			find_ra(&tmp);
		tmp = tmp->next;
	}
}

void		find_rra(t_cmd **cmd)
{
	t_cmd *tmp;

	tmp = *cmd;
	if (tmp->next && ft_strequ(tmp->next->abbr, "rrb"))
		find_rra(&(tmp->next));
	while (tmp->next && ft_strequ(tmp->next->abbr, "rrr"))
		tmp = tmp->next;
	if (tmp->next && ft_strequ(tmp->next->abbr, "rra"))
	{
		free((*cmd)->abbr);
		(*cmd)->abbr = ft_strdup("rrr");
		remove_cmd(&tmp);
	}
}

void		parse_rrb(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		if (ft_strequ(tmp->abbr, "rrb"))
			find_rra(&tmp);
		tmp = tmp->next;
	}
}

void		parse_cmds(t_cmd **cmd)
{
	parse_ra(cmd);
	parse_rb(cmd);
	parse_rra(cmd);
	parse_rrb(cmd);
}
