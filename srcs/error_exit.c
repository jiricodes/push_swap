/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:09:16 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/16 11:23:11 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *str)
{
	ft_printf("{RED}ERROR EXIT:{EOC} %s\n", str);
	exit(-1);
}

void	ps_usage_exit(void)
{
	ft_printf("{GREEN}{U}Push_Swap Usage:{EOC}\n\n");
	ft_printf("Syntax:\t./push_swap [-flags] .. [numbers] ..\n\n");
	ft_printf("Available flags:\n");
	ft_printf("-v\t\tEnables visualisation\n");
	ft_printf("-f [FILENAME]\tReads data from the file\n");
	ft_printf("-s [SECONDS]\tEnables delay in visualizer\n");
	ft_printf("-t\t\tShows total number of steps\n");
	ft_printf("-c [INT_COLOR]\tChanges visualiser color\n");
	ft_printf("-u\t\tShows usage\n");
	ft_printf("-i\t\tShows program informations. If selected, normal\n");
	ft_printf("\t\tprogram functionality is disabled!\n");
	exit(-1);
}

void	ps_info_exit(void)
{
	ft_printf("\n{GREEN}{U}Push_Swap Project{EOC}\n");
	ft_printf("Created by:\n\tjnovotny\n\tat HIVE Helsinki\n\t12/2019\n");
	ft_printf("\nMore info to be added.\n");
	exit(-1);
}
