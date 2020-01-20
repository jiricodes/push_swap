/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:09:16 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 19:03:51 by jnovotny         ###   ########.fr       */
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
	ft_printf("-v\t\tEnables visualisation (max 900 numbers)\n");
	ft_printf("-f [FILENAME]\tReads data from the file\n");
	ft_printf("-t\t\tShows total number of steps\n");
	ft_printf("-c [INT_COLOR]\tChanges visualiser color\n");
	ft_printf("-u\t\tShows usage\n");
	ft_printf("-i\t\tShows program informations. If selected, normal\n");
	ft_printf("\t\tprogram functionality is disabled!\n");
	exit(0);
}

void	ch_usage_exit(int error)
{
	if (error)
		ft_printf("{RED}{B}Error{EOC}\n\n");
	ft_printf("{GREEN}{U}Checker Usage:{EOC}\n\n");
	ft_printf("Syntax:\t./checker [-flags] .. [numbers] ..\n\n");
	ft_printf("Available flags:\n");
	ft_printf("-v\t\tEnables visualisation (max 900 numbers)\n");
	ft_printf("-f [FILENAME]\tReads data from the file\n");
	ft_printf("-c [INT_COLOR]\tChanges visualiser color\n");
	ft_printf("-u\t\tShows usage\n");
	ft_printf("-i\t\tShows program informations. If selected, normal\n");
	ft_printf("\t\tprogram functionality is disabled!\n");
	exit(0);
}

void	ps_info_exit(void)
{
	ft_printf("\n{GREEN}{U}Push_Swap Project{EOC}\n");
	ft_printf("Created by:\n\tjnovotny\n\tat HIVE Helsinki\n\t01/2020\n");
	ft_printf("\nThe project aims to sort given array of unique numbers\n");
	ft_printf("using two stacks (A and B) and only following:\n\n");
	system("cat man/legend.txt");
	ft_printf("\n\nThe binary {BLUE}{B}push_swap{EOC} should return");
	ft_printf(" a list of operations\n");
	ft_printf("which if performed on given array of numbers\n");
	ft_printf("should make it sorted.\n");
	ft_printf("\nThe binary {BLUE}{B}checker{EOC} performs given commands\n");
	ft_printf("on given array. And returns message whether\n");
	ft_printf("the final stack is sorted or not.\n\n");
	exit(0);
}
