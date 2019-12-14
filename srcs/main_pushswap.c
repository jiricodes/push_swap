/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:56:42 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/14 19:20:50 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			i;
	t_ps		ps;

	i = 0;
	init_ps(&ps);
	while (++i < ac)
		ps.a->lst = create_back(ps.a->lst, ft_atoi(av[i]));
	if (!check_valid(ps.a->lst))
		error_exit("Ivalid list of numbers (contains duplicates)");
	push_swap(&ps);
	// while(1){}
	return (0);
}
