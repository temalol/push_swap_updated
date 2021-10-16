/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 23:34:36 by nmustach          #+#    #+#             */
/*   Updated: 2021/10/15 15:53:45 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stacklen_wo_delim(t_node *stack_a)
{
	size_t	len;

	len = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		len++;
	}
	return (len);
}

void	apply_to_b(t_node **stack_a, t_node **stack_b, size_t key)
{
	int		stlen;

	stlen = stacklen_wo_delim(*stack_a);
	while (stlen--)
	{
		if ((*stack_a)->stay)
			ra(stack_a, key);
		else
			pb(stack_a, stack_b, key);
		vizu_wrapper(*stack_a, *stack_b, key);
	}
}

size_t	stacklen(t_node *stack_a)
{
	size_t	len;

	len = 0;
	while (stack_a && !stack_a->delim)
	{
		stack_a = stack_a->next;
		len++;
	}
	return (len);
}
