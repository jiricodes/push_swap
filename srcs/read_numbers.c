/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 11:33:05 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/10 10:18:48 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_fetch_numbers(t_ps *ps, int ac, char **av)
{
	int i;

	if (FLG_F)
	{
		i = 1;
		while (!ft_strstr(av[i], "-f"))
			i++;
		i++;
		if ((ps->flags.fd = open(av[i], O_RDONLY)) == -1)
			error_exit("Failed to open the given file.");
		ps_readfile(ps);
	}
	else
		ps_readargs(ps, ac, av);
}

void	ps_readfile(t_ps *ps)
{
	char	*str;
	int		i;

	while (get_next_line(ps->flags.fd, &str) > 0)
	{
		i = 0;
		while (str[i])
		{
			while (ft_isspace(str[i]))
				i++;
			if (str[i] == '\0')
				break ;
			if (!ft_isdigit(str[i]) && !ft_isspace(str[i]))
				error_exit("File contains invalid characters");
			A_LST = create_back(A_LST, ft_atoi(&str[i]));
			ps->org = create_back(ps->org, ft_atoi(&str[i]));
			while (isdigit(str[i]))
				i++;
		}
		free(str);
	}
}

void	ps_readargs(t_ps *ps, int ac, char **av)
{
	int i;

	i = ac - 1;
	while (i > 0 && (isdigit(av[i][0]) ||\
		(av[i][0] == '-' && isdigit(av[i][1]))))
		i--;
	if (ft_strstr(av[i], "-s") || ft_strstr(av[i], "-c"))
		i++;
	while (++i < ac)
	{
		A_LST = create_back(A_LST, ft_atoi(av[i]));
		ps->org = create_back(ps->org, ft_atoi(av[i]));
	}
}
