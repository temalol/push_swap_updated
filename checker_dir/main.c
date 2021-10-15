/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:46:52 by nmustach          #+#    #+#             */
/*   Updated: 2021/10/15 20:47:42 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	size_t	m[3];
	size_t	f;
	
	m[0] = 0;
	m[2] = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{	
		m[1] = hangle_keys(argv[1]);
		if (!push_values_to_stack(argc, argv, &stack_a, m))
			return (std_err(stack_a, stack_b, &f));
		if (stack_a->next)
		{
			if (!read_instructions(&stack_a, &stack_b))
				return (std_err(stack_a, stack_b, &f));
			if (is_sorted(stack_a, stack_b))
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
		}
		free_both_stacks(stack_a, stack_b, &m[2]);
		if (m[1] == 1)
			ft_printf("Malloc:%lu Free:%lu", m[0], m[2]);
	}
	return (0);
}
