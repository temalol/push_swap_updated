/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 03:14:04 by nmustach          #+#    #+#             */
/*   Updated: 2020/04/01 16:38:55 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printstack_vizu(t_node *stack_a, t_node *stack_b)
{
	ft_printf("\e[1;1H\e[2J");
	ft_printf(ANSI_YELLOW"A       B"ANSI_RESET"\n__________\n");
	while (stack_a || stack_b)
	{
		if (stack_a != NULL)
			ft_printf("%d | ", stack_a->val);
		else
			ft_printf(ANSI_RED"x"ANSI_RESET"  | ");
		if (stack_b != NULL)
			ft_printf("%d", stack_b->val);
		else
			ft_printf(ANSI_RED"x"ANSI_RESET);
		ft_printf("\n");
		if (stack_a != NULL)
			stack_a = stack_a->next;
		if (stack_b != NULL)
			stack_b = stack_b->next;
	}
	ft_printf("\n");
	sleep(1);
}
