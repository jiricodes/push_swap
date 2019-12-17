/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:56:42 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/17 12:05:39 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			i;
	t_ps		ps;
	char		*flgs;

	i = 0;
	init_ps(&ps);
	flgs = ft_getflags_arg(ac, av, FLG_STR);
	ps_flags(&ps, flgs);
	free(flgs);
	ps_fetch_flgdata(&ps, ac, av);
	ps_fetch_numbers(&ps, ac, av);
	if (!check_valid(ps.a->lst))
		error_exit("Ivalid list of numbers (contains duplicates)");
	push_swap(&ps);
	// while(1){}
	return (0);
}
