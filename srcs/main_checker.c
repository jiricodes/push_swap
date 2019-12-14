/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:33:09 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/14 11:54:13 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	int			i;
	int			k;
	t_int_list	*a;
	t_int_list	*b;
	t_cmd		*cmds;
	char		*str;

	if (ac == 1)
		return (0);
	i = 0;
	a = NULL;
	b = NULL;
	cmds = NULL;
	while (++i < ac)
	{
		k = 0;
		while (av[i][k] != '\0')
		{
			if (!ft_isdigit(av[i][k]))
				error_exit("Arguments are not valid numbers.");
			k++;
		}
		a = create_back(a, ft_atoi(av[i]));
	}
	while (get_next_line(0, &str) > 0)
	{
		cmds = create_cmd_back(cmds, str);
		free(str);
	}
	ps_checker(&a, &b, cmds);
	clear_cmds(&cmds);
	clear_list(&a);
	clear_list(&b);
	while(1){}
	return (0);
}
