/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:53:07 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 15:29:16 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		find_rra_rot(t_cmd **cmd)
{
	t_cmd *tmp;

	tmp = *cmd;
	if (tmp->next && ft_strequ(tmp->next->abbr, "ra"))
		find_rra_rot(&(tmp->next));
	if (tmp->next && ft_strequ(tmp->next->abbr, "rra"))
	{
		remove_cmd(&(tmp->next));
		remove_cmd(&tmp);
	}
}

static void		parse_ra_rot(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		if (ft_strequ(tmp->abbr, "ra"))
			find_rra_rot(&tmp);
		tmp = tmp->next;
	}
}

static void		find_ra_rot(t_cmd **cmd)
{
	t_cmd *tmp;

	tmp = *cmd;
	if (tmp->next && ft_strequ(tmp->next->abbr, "rra"))
		find_ra_rot(&(tmp->next));
	if (tmp->next && ft_strequ(tmp->next->abbr, "ra"))
	{
		remove_cmd(&(tmp->next));
		remove_cmd(&tmp);
	}
}

static void		parse_rra_rot(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		if (ft_strequ(tmp->abbr, "rra"))
			find_ra_rot(&tmp);
		tmp = tmp->next;
	}
}

void			parse_rotates(t_cmd **cmd)
{
	parse_ra_rot(cmd);
	parse_rra_rot(cmd);
}
