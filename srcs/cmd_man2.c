/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_man2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:41:20 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/10 09:59:19 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Free CMD
*/

void	free_cmd(t_cmd *node)
{
	free(node->abbr);
	free(node);
}

/*
** Returns amount of commands in the list
*/

int		count_cmd_list(t_cmd *list)
{
	int cnt;

	cnt = 0;
	while (list)
	{
		cnt++;
		list = list->next;
	}
	return (cnt);
}
