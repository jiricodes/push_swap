/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:11:57 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/09 17:33:20 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			remove_cmd(t_cmd **cmd)
{
	t_cmd *node;

	node = (*cmd)->next;
	(*cmd)->next = (*cmd)->next->next;
	node->next = NULL;
	free_cmd(node);
}

static void		find_rb(t_cmd **cmd)
{
	t_cmd *tmp;

	tmp = *cmd;
	if (tmp->next && ft_strequ(tmp->next->abbr, "ra"))
		find_rb(&(tmp->next));
	while (tmp->next && ft_strequ(tmp->next->abbr, "rr"))
		tmp = tmp->next;
	if (tmp->next && ft_strequ(tmp->next->abbr, "rb"))
	{
		free((*cmd)->abbr);
		(*cmd)->abbr = ft_strdup("rr");
		remove_cmd(&tmp);
	}
}

static void		parse_ra(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		if (ft_strequ(tmp->abbr, "ra"))
			find_rb(&tmp);
		tmp = tmp->next;
	}
}

static void		find_rrb(t_cmd **cmd)
{
	t_cmd *tmp;

	tmp = *cmd;
	if (tmp->next && ft_strequ(tmp->next->abbr, "rra"))
		find_rrb(&(tmp->next));
	while (tmp->next && ft_strequ(tmp->next->abbr, "rrr"))
		tmp = tmp->next;
	if (tmp->next && ft_strequ(tmp->next->abbr, "rrb"))
	{
		free((*cmd)->abbr);
		(*cmd)->abbr = ft_strdup("rrr");
		remove_cmd(&tmp);
	}
}

static void		parse_rra(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		if (ft_strequ(tmp->abbr, "rra"))
			find_rrb(&tmp);
		tmp = tmp->next;
	}
}

static void		find_ra(t_cmd **cmd)
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

static void		parse_rb(t_cmd **cmd)
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

static void		find_rra(t_cmd **cmd)
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

static void		parse_rrb(t_cmd **cmd)
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

void			parse_cmds(t_cmd **cmd)
{
	parse_ra(cmd);
	parse_rb(cmd);
	parse_rra(cmd);
	parse_rrb(cmd);
}
