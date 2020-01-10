/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:41:20 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/09 16:45:46 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Creates a node for t_cmd
*/

t_cmd	*create_cmd_node(char *abbr)
{
	t_cmd *node;

	node = (t_cmd*)malloc(sizeof(t_cmd));
	if (!node)
		error_exit("malloc @create_node");
	node->abbr = ft_strdup(abbr);
	node->next = NULL;
	return (node);
}

/*
** Add a node to the beginning of a list
*/

t_cmd	*add_cmd_front(t_cmd *head, t_cmd *node)
{
	if (!head)
		return (node);
	node->next = head;
	return (node);
}

/*
** Add a node to the end of a list
*/

t_cmd	*add_cmd_back(t_cmd *head, t_cmd *node)
{
	t_cmd *tmp;

	if (!head)
		return (node);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (head);
}

/*
**	Create a node at the first position;
*/

t_cmd	*create_cmd_front(t_cmd *head, char *abbr)
{
	t_cmd *node;

	node = create_cmd_node(abbr);
	return (add_cmd_front(head, node));
}

/*
**	Create a node at the last position;
*/

t_cmd	*create_cmd_back(t_cmd *head, char *abbr)
{
	t_cmd *node;

	node = create_cmd_node(abbr);
	return (add_cmd_back(head, node));
}

/*
**	Free CMD
*/

void	free_cmd(t_cmd *node)
{
	free(node->abbr);
	free(node);
}
