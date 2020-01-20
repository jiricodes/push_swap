/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:33:09 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 17:28:29 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_ps		ps;
	char		*flgs;
	char		*str;

	if (ac < 2)
		ch_usage_exit();
	init_ps(&ps);
	flgs = ft_getflags_arg(ac, av, FLG_STR);
	ps_flags(&ps, flgs);
	free(flgs);
	ps_fetch_flgdata(&ps, ac, av);
	ps_fetch_numbers(&ps, ac, av);
	while (get_next_line(0, &str) > 0)
	{
		ps.cmds = create_cmd_back(ps.cmds, str);
		free(str);
	}
	ps_info(&ps);
	ps_checker(&(ps.a->lst), &(ps.b->lst), ps.cmds);
	if (ps.flags.v)
		visualise_ps(&ps);
	clear_ps(&ps);
	// while(1){}
	return (0);
}
