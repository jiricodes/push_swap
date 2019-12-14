/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:54:42 by jnovotny          #+#    #+#             */
/*   Updated: 2019/12/14 10:49:25 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

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


/*
** Main Push_Swap hubs and functions
*/

void		ps_checker(t_int_list **a, t_int_list **b, t_cmd *cmd);
void		is_correct_ps(t_int_list *a, t_int_list *b);

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
void	clear_list(t_int_list **list);

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

/*
** Supportive tools
*/

void		error_exit(char *str);
int			is_sort_list(t_int_list *list);

#endif