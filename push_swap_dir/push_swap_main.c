/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 23:29:48 by nmustach          #+#    #+#             */
/*   Updated: 2021/10/15 20:26:28 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	size_t	m[2];
	size_t	f;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		m[1] = hangle_keys(argv[1]);
		if (!push_values_to_stack(argc, argv, &stack_a, m))
			return (std_err(stack_a, stack_b, &f));
		if (!is_sorted(stack_a, stack_b) && stack_a->next)
			sort(&stack_a, &stack_b);
		free_both_stacks(stack_a, stack_b, &f);
		if (m[1] == 1)
			ft_printf("Malloc:%lu Free:%lu", m, f);
	}
	return (0);
}
