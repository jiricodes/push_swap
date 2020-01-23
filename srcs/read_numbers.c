/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 11:33:05 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/23 19:51:07 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_fetch_numbers(t_ps *ps, int ac, char **av)
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

static void	nb_parse_str(t_ps *ps, char *str)
{
	int			i;
	long long	nb;

	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i] == '\0')
			break ;
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i]) && str[i] != '-'\
			&& str[i] != '+')
			error_exit("List contains invalid characters");
		if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
			error_exit("List contains '-'/'+' not followed by a digit");
		nb = ft_latoi(&str[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error_exit("List contains number out of integer range");
		A_LST = create_back(A_LST, (int)nb);
		ps->org = create_back(ps->org, (int)nb);
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (ft_isdigit(str[i]))
			i++;
	}
}

void		ps_readfile(t_ps *ps)
{
	char	*str;

	while (get_next_line(ps->flags.fd, &str) > 0)
	{
		nb_parse_str(ps, str);
		free(str);
	}
}

void		ps_readargs(t_ps *ps, int ac, char **av)
{
	int i;

	i = ac - 1;
	while (i > 0 && (ft_isdigit(av[i][0]) ||\
		(av[i][0] == '-' && ft_isdigit(av[i][1])) ||\
		(av[i][0] == '+' && ft_isdigit(av[i][1]))))
		i--;
	if ((ft_strstr(av[i], "-s") || ft_strstr(av[i], "-c")) && i < ac - 1)
		i++;
	if (i == ac - 1)
		error_exit("Invalid input (use flag -u for more information)");
	if (((av[i][0] == '-' || av[i][0] == '+') && ft_strlen(av[i]) == 1))
		error_exit("List contains '-'/'+' without a follow up digit");
	if (av[i][0] == '+' && !ft_isdigit(av[i][1]))
		error_exit("List contains invalid symbol");
	while (++i < ac)
		nb_parse_str(ps, av[i]);
}
