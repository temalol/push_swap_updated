/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:07:33 by nmustach          #+#    #+#             */
/*   Updated: 2021/10/15 20:44:15 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_node
{
	long			val;
	int				index;
	int				stay;
	int				delim;
	int				ra_to_top;
	int				rra_to_top;
	int				rb_to_top;
	int				rrb_to_top;
	int				rr_to_top;
	int				rrr_to_top;
	int				r_sum;
	struct s_node	*next;
}				t_node;

# define NUM_OF_INSTR 11

int				ft_atoi_validate(const char *str, long *num);
int				push_values_to_stack(int argc, char **argv,
					t_node **stack_a, size_t *m);
int				ft_push(long val, t_node **stack_a, size_t *m);
int				ft_isdigit(int c);
void			stack_rev(t_node **stack);
int				check_dublicates(long val, t_node *stack);
int				read_instructions(t_node **stack_a, t_node **stack_b);
void			execute_instruction(int ins_num,
					t_node **stack_a, t_node **stack_b);
int				is_sorted(t_node *stack_a, t_node *stack_b);
void			free_both_stacks(t_node *stack_a, t_node *stack_b, size_t *f);
int				std_err(t_node *stack_a, t_node *stack_b, size_t *f);
int				is_number(char *str);
int				parse_and_push(char *str, t_node **stack_a, size_t *m);
int				validate_sign(const char *str, int *flag, int *i);
int				hangle_keys(char *argv);

/*
** -------------------------- Debug Functions --------------------------------
*/
void			printstack(t_node *stack_a, t_node *stack_b);
void			printstack_with_ind(t_node *stack_a, t_node *stack_b);
/*
** -------------------------- Stack Functions --------------------------------
*/

void			sa(t_node **stack_a, int output);
void			sb(t_node **stack_b, int output);
void			pa(t_node **stack_a, t_node **stack_b, int output);
void			pb(t_node **stack_a, t_node **stack_b, int output);
void			ra(t_node **stack_a, int output);
void			rb(t_node **stack_b, int output);
void			rra(t_node **stack_a, int output);
void			rrb(t_node **stack_b, int output);

#endif
