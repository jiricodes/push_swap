/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:33:09 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/19 15:44:16 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	int			i;
	int			k;
	char		*str;
	t_ps		*ps;


	if (ac == 1)
		return (0);
	ps = (t_ps *)malloc(sizeof(t_ps));
	init_ps(ps);
	i = 0;
	while (++i < ac)
	{
		k = 0;
		while (av[i][k] != '\0')
		{
			if (!ft_isdigit(av[i][k]))
				error_exit("Arguments are not valid numbers.");
			k++;
		}
		ps->org = create_back(ps->org, ft_atoi(av[i]));
		A_LST = create_back(A_LST, ft_atoi(av[i]));
	}
	while (get_next_line(0, &str) > 0)
	{
		ps->cmds = create_cmd_back(ps->cmds, str);
		free(str);
	}
	ps_info(ps);
	ps_checker(&(A_LST), &(B_LST), CMD);
	visualise_ps(ps);
	clear_ps(ps);
	// while(1){}
	return (0);
}
