/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_values_to_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:08:15 by nmustach          #+#    #+#             */
/*   Updated: 2021/10/15 20:48:38 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_both_stacks(t_node *stack_a, t_node *stack_b, size_t *f)
{
	t_node	*tmp;

	while (stack_a)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
		*f = *f + 1;
	}
	while (stack_b)
	{
		tmp = stack_b;
		stack_b = stack_b->next;
		free(tmp);
		*f = *f + 1;
	}
}

void	stack_rev(t_node **stack)
{
	t_node	*tmpnext;
	t_node	*tmp2;

	if ((*stack)->next != NULL)
	{
		tmpnext = (*stack)->next;
		tmp2 = (*stack);
		(*stack)->next = NULL;
		(*stack) = tmpnext;
		while ((*stack)->next)
		{
			tmpnext = (*stack)->next;
			(*stack)->next = tmp2;
			tmp2 = (*stack);
			(*stack) = tmpnext;
		}
		(*stack)->next = tmp2;
	}
}

int	ft_push(long val, t_node **stack_a, size_t *m)
{
	t_node	*tmp;

	if ((*stack_a) == NULL)
	{
		*stack_a = malloc(sizeof(t_node));
		if (*stack_a == NULL)
			exit(0);
		*m = *m + 1;
		(*stack_a)->next = NULL;
		(*stack_a)->val = val;
		(*stack_a)->stay = 0;
		return (1);
	}
	tmp = malloc(sizeof(t_node));
	if (tmp == NULL)
		exit(0);
	*m = *m + 1;
	tmp->val = val;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	(*stack_a)->stay = 0;
	(*stack_a)->delim = 0;
	return (1);
}

int	string_args_case(char **argv, t_node **stack_a, size_t *m, int argcnt)
{
	int	i;

	i = is_number(argv[argcnt]);
	if (i > 0 && argv[argcnt][i + 1] && (!argv[argcnt][i]
	|| argv[argcnt][i] == ' '))
	{
		if (!parse_and_push(argv[argcnt], stack_a, m))
			return (0);
		stack_rev(stack_a);
		return (1);
	}
	return (0);
}

int	push_values_to_stack(int argc, char **argv, t_node **stack_a, size_t *m)
{
	int		argcnt;
	long	num;

	if (m[1] > 0)
		argcnt = 2;
	else
		argcnt = 1;
	if (argc == 2 || argc == 3)
		return (string_args_case(argv, stack_a, m, argcnt));
	while (argcnt <= argc - 1)
	{
		if (!ft_atoi_validate(argv[argcnt], &num)
			|| check_dublicates(num, *stack_a))
			return (0);
		ft_push(num, stack_a, m);
		argcnt++;
	}
	stack_rev(stack_a);
	return (1);
}
