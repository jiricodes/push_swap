/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:56:42 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/12 18:36:06 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			i;
	t_int_list	*a;
	t_int_list	*b;

	i = 0;
	a = NULL;
	b = NULL;
	while (++i < ac)
		a = create_back(a, ft_atoi(av[i]));
	// 2 1 3 6 5 8
	// sa  pb pb pb ra rb rra rrb sa pa pa pa
	ft_printf("\nOriginal:\n");
	print_list(a, "a", ' ');
	print_list(b, "b", ' ');
	a = swap_top2(a);
	ft_printf("\nsa:\n");
	print_list(a, "a", ' ');
	print_list(b, "b", ' ');
	push(&b, &a);
	push(&b, &a);
	push(&b, &a);
	ft_printf("\npb pb pb:\n");
	print_list(a, "a", ' ');
	print_list(b, "b", ' ');
	a = rotate(a);
	b = rotate(b);
	ft_printf("\nra rb:\n");
	print_list(a, "a", ' ');
	print_list(b, "b", ' ');
	a = rev_rotate(a);
	b = rev_rotate(b);
	ft_printf("\nrra rrb:\n");
	print_list(a, "a", ' ');
	print_list(b, "b", ' ');
	a = swap_top2(a);
	ft_printf("\nsa:\n");
	print_list(a, "a", ' ');
	print_list(b, "b", ' ');
	push(&a, &b);
	ft_printf("\npa:\n");
	print_list(a, "a", ' ');
	print_list(b, "b", ' ');
	push(&a, &b);
	ft_printf("\npa:\n");
	print_list(a, "a", ' ');
	print_list(b, "b", ' ');
	push(&a, &b);
	ft_printf("\npa:\n");
	ft_printf("\nResult:\n");
	print_list(a, "a", ' ');
	print_list(b, "b", ' ');
	// while(1){}
	return (0);
}
