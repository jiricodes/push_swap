/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:17:16 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/20 19:24:52 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Concats flags into a string. If not valid flag found, "?" is returned.
*/

char		*ft_getflags_arg(int ac, char **av, char *range)
{
	char	*flags;
	int		i;
	int		j;

	i = 0;
	j = 0;
	flags = ft_strnew(ac);
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			if (ft_isdigit(av[i][1]))
				continue;
			if (!ft_strchr(range, av[i][1]))
			{
				free(flags);
				return ("?");
			}
			flags[j] = av[i][1];
			j++;
		}
	}
	return (flags);
}

void		ps_flags(t_ps *ps, char *flags)
{
	ft_bzero(&(ps->flags), sizeof(t_flag));
	if (ft_strchr(flags, '?') || ft_strchr(flags, 'u'))
		ps_usage_exit();
	if (ft_strchr(flags, 'i'))
		ps_info_exit();
	if (ft_strchr(flags, 'f'))
		ps->flags.f = 1;
	if (ft_strchr(flags, 'v'))
		ps->flags.v = 1;
	if (ft_strchr(flags, 's'))
		ps->flags.s = 1;
	if (ft_strchr(flags, 't'))
		ps->flags.t = 1;
	if (ft_strchr(flags, 'c'))
		ps->flags.c = 1;
}

void		ch_flags(t_ps *ps, char *flags)
{
	ft_bzero(&(ps->flags), sizeof(t_flag));
	if (ft_strchr(flags, '?') || ft_strchr(flags, 'u'))
		ch_usage_exit(0);
	if (ft_strchr(flags, 'i'))
		ps_info_exit();
	if (ft_strchr(flags, 'f'))
		ps->flags.f = 1;
	if (ft_strchr(flags, 'v'))
		ps->flags.v = 1;
	if (ft_strchr(flags, 's'))
		ps->flags.s = 1;
	if (ft_strchr(flags, 't'))
		ps->flags.t = 1;
	if (ft_strchr(flags, 'c'))
		ps->flags.c = 1;
}

void		ps_fetch_flgdata(t_ps *ps, int ac, char **av)
{
	int i;

	if (FLG_S)
	{
		i = 1;
		while (!ft_strstr(av[i], "-s") && i < ac)
			i++;
		if (i == ac - 1)
			error_exit("No parameter for flag -s");
		i++;
		ps->flags.sec = ft_atoi(av[i]);
	}
	if (FLG_C)
	{
		i = 1;
		while (!ft_strstr(av[i], "-c") && i < ac)
			i++;
		if (i == ac - 1)
			error_exit("No parameter for flag -c");
		i++;
		ps->flags.color = ft_atoi(av[i]);
	}
}
