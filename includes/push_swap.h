/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:54:42 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/17 12:51:04 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "vfx_push_swap.h"

# define FLG_STR "fvstciu"
# define FLG_F ps->flags.f
# define FLG_V ps->flags.v
# define FLG_S ps->flags.s
# define FLG_T ps->flags.t
# define FLG_C ps->flags.c
# define A_LST ps->a->lst
# define A_CNT ps->a->count
# define A_MAX ps->a->max
# define A_MIN ps->a->min
# define A_TOP ps->a->lst->nb
# define A_2ND ps->a->lst->next->nb
# define A_LAST get_last(ps->a->lst)
# define B_LST ps->b->lst
# define B_CNT ps->b->count
# define B_MAX ps->b->max
# define B_MIN ps->b->min
# define B_TOP ps->b->lst->nb
# define B_2ND ps->b->lst->next->nb
# define B_LAST get_last(ps->b->lst)
# define CMD ps->cmds

typedef struct	s_nblist
{
	int				nb;
	struct s_nblist *next;
}				t_int_list;

typedef struct	s_commands
{
	char				*abbr;
	struct s_commands	*next;
}				t_cmd;

typedef struct	s_stack
{
	int			count;
	int			min;
	int			max;
	t_int_list	*lst;
}				t_stk;

typedef struct	s_flags
{
	char	f;
	int		fd;
	char	v;
	char	s;
	int		sec;
	char	t;
	char	c;
	int		color;
}				t_flg;

typedef struct s_push_swap
{
	int			count;
	int			min;
	int			max;
	t_int_list	*org;
	t_stk		*a;
	t_stk		*b;
	t_cmd		*cmds;
	t_flg		flags;
	t_ps_vfx	*vfx;
	t_stk		*vfx_a;
	t_stk		*vfx_b;
	t_cmd		*vfx_cmds;
}				t_ps;

/*
** Main Push_Swap hubs and functions
*/

void		ps_checker(t_int_list **a, t_int_list **b, t_cmd *cmd);
void		is_correct_ps(t_int_list *a, t_int_list *b);
void		ps_info(t_ps *ps);
void		push_swap(t_ps *ps);
void		do_pb(t_ps *ps);
void		do_pa(t_ps *ps);

/*
** List Management Functions
*/

t_int_list	*create_node(int nb);
t_int_list	*add_front(t_int_list *head, t_int_list *node);
t_int_list	*add_back(t_int_list *head, t_int_list *node);
t_int_list	*create_front(t_int_list *head, int nb);
t_int_list	*create_back(t_int_list *head, int nb);
t_int_list	*extract_first(t_int_list **head);
t_int_list	*extract_last(t_int_list **head);
void		clear_list(t_int_list **list);

/*
** Push Swap functions
** sa : swap a - swap the first 2 elements at the top of stack a.
**		Do nothing if there is only one or no elements).
** sb : swap b - swap the first 2 elements at the top of stack b.
**		Do nothing if there is only one or no elements).
** ss : sa and sb at the same time.
** pa : push a - take the first element at the top of b and put it
**		at the top of a. Do nothing if b is empty.
** pb : push b - take the first element at the top of a and put it
**		at the top of b. Do nothing if a is empty.
** ra : rotate a - shift up all elements of stack a by 1. The first
**		element becomes the last one.
** rb : rotate b - shift up all elements of stack b by 1. The first
**		element becomes the last one.
** rr : ra and rb at the same time.
** rra : reverse rotate a - shift down all elements of stack a by 1.
**		The last element becomes the first one.
** rrb : reverse rotate b - shift down all elements of stack b by 1.
**		The last element becomes the first one.
** rrr : rra and rrb at the same time.
*/

t_int_list	*swap_top2(t_int_list *list);
void		push(t_int_list **dest, t_int_list **src);
t_int_list	*rotate(t_int_list *list);
t_int_list	*rev_rotate(t_int_list *list);
void	do_pb(t_ps *ps);
void	do_pa(t_ps *ps);
void	do_sa(t_ps *ps);
void	do_sb(t_ps *ps);
void	do_ra(t_ps *ps);
void	do_rb(t_ps *ps);
void	do_rra(t_ps *ps);
void	do_rrb(t_ps *ps);

/*
** Commands list and parsing
*/

t_cmd		*create_cmd_node(char *abbr);
t_cmd		*add_cmd_front(t_cmd *head, t_cmd *node);
t_cmd		*add_cmd_back(t_cmd *head, t_cmd *node);
t_cmd		*create_cmd_front(t_cmd *head, char *abbr);
t_cmd		*create_cmd_back(t_cmd *head, char *abbr);
void		cmd_to_func(t_int_list **a, t_int_list **b, char *cmd);
void		cmd_to_func2(t_int_list **a, t_int_list **b, char *cmd);
void		clear_cmds(t_cmd **cmds);

/*
** List Printing
*/

void		print_list(t_int_list *list, char *name, char separator);
void		print_cmd_list(t_cmd *list);

/*
**	Reading list of numbers
*/

void	ps_fetch_numbers(t_ps *ps, int ac, char **av);
void	ps_readfile(t_ps *ps);
void	ps_readargs(t_ps *ps, int ac, char **av);

/*
** Supportive tools
*/

void		error_exit(char *str);
void		ps_usage_exit(void);
void		ps_info_exit(void);
int			is_sort_list(t_int_list *list);
int			is_rot_sort(t_stk *stack);
int			find_min(t_int_list *list);
int			find_max(t_int_list *list);
int			count_list(t_int_list *list);
int			get_last(t_int_list *list);
int			find_nb_pos(t_int_list *list, int nb);
int			find_slot_rotsort(t_int_list *list, int nb, int max);
int			count_cmd_list(t_cmd *list);
void		init_ps(t_ps *ps);
void		clear_ps(t_ps *ps);
int			check_valid(t_int_list *list);
int			find_slot(t_int_list *list, int nb);
void		ps_flags(t_ps *ps, char *flags);
char		*ft_getflags_arg(int ac, char **av, char *range);
void		ps_fetch_flgdata(t_ps *ps, int ac, char **av);

/*
** PUSH_SWAP vfx environment initialization
*/

void	vfx_init(t_ps *ps, t_ps_vfx *vfx);
void	vfx_init_elems(t_ps *ps, t_ps_vfx *vfx);

/*
** General Push_Swap VFX functions
*/

void	visualise_ps(t_ps *ps);
int		ps_vfx_key_press(int key, t_ps *ps);
void	vfx_copy_info(t_ps *ps);

#endif