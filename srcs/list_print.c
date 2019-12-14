/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:40:16 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/14 18:07:28 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Prints all NB's from the list separated with given char.
** Starting with given string. Ending with '\n'
*/

void	print_list(t_int_list *list, char *name, char separator)
{
	if (name)
		ft_printf("%s: ", name);
	else
		ft_printf("Noname: ");
	if (!list)
	{
		ft_printf("\n");
		return ;
	}
	while (list->next)
	{
		ft_printf("%d%c", list->nb, separator);
		list = list->next;
	}
	ft_printf("%d\n", list->nb);
	return ;
}

/*
** Prints list of commands
*/

void	print_cmd_list(t_cmd *list)
{
	if (!list)
		ft_printf("\n");
	else
		while (list)
		{
			ft_printf("%s\n", list->abbr);
			list = list->next;
		}
	return ;
}
