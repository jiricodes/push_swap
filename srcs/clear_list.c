/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 10:18:31 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/14 10:32:32 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*extract_first_cmd(t_cmd **head)
{
	t_cmd *first;

	if (!head || !*head)
		return (NULL);
	if (!(*head)->next)
	{
		first = *head;
		*head = NULL;
	}
	else
	{
		first = *head;
		*head = (*head)->next;
		first->next = NULL;
	}
	return (first);
}

void	clear_cmds(t_cmd **cmds)
{
	t_cmd *tmp;

	while ((tmp = extract_first_cmd(cmds)))
	{
		ft_strdel(&(tmp->abbr));
		free(tmp);
	}
}

void	clear_list(t_int_list **list)
{
	t_int_list *tmp;

	while ((tmp = extract_first(list)))
		free(tmp);
}
