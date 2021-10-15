/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:45:11 by nmustach          #+#    #+#             */
/*   Updated: 2021/10/15 16:44:02 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(t_node *stack_a, t_node *stack_b)
{
	if (stack_a && stack_a->next && !stack_b)
	{
		while (stack_a->next)
		{
			if (stack_a->val > stack_a->next->val)
				return (0);
			stack_a = stack_a->next;
		}
		return (1);
	}
	return (0);
}

void	execute_more(int ins_num, t_node **stack_a, t_node **stack_b)
{
	if (ins_num == 5)
		ra(stack_a, 0);
	if (ins_num == 6)
		rb(stack_b, 0);
	if (ins_num == 7)
	{
		ra(stack_a, 0);
		rb(stack_b, 0);
	}
	if (ins_num == 8)
		rra(stack_a, 0);
	if (ins_num == 9)
		rrb(stack_b, 0);
	if (ins_num == 10)
	{
		rra(stack_a, 0);
		rrb(stack_b, 0);
	}
}

void	execute_instruction(int ins_num, t_node **stack_a, t_node **stack_b)
{
	if (ins_num <= 3)
	{
		if (ins_num == 0)
			sa(stack_a, 0);
		if (ins_num == 1)
			sb(stack_b, 0);
		if (ins_num == 2)
		{
			sa(stack_a, 0);
			sb(stack_b, 0);
		}
	}
	if (ins_num > 2 && ins_num < 5)
	{
		if (ins_num == 3)
			pa(stack_a, stack_b, 0);
		if (ins_num == 4)
			pb(stack_a, stack_b, 0);
	}
	if (ins_num >= 5)
		execute_more(ins_num, stack_a, stack_b);
}

int	validate_instruction(char *ins)
{
	const char	*a[11];
	int			cnt;

	cnt = 0;
	a[0] = "sa";
	a[1] = "sb";
	a[2] = "ss";
	a[3] = "pa";
	a[4] = "pb";
	a[5] = "ra";
	a[6] = "rb";
	a[7] = "rr";
	a[8] = "rra";
	a[9] = "rrb";
	a[10] = "rrr";
	while (cnt < NUM_OF_INSTR)
	{
		if (ft_strequ(ins, a[cnt]))
			return (cnt);
		cnt++;
	}
	return (-1);
}

int	read_instructions(t_node **stack_a, t_node **stack_b)
{
	int		ins_num;
	char	input[2];
	char	tmp[5];
	int		tmpind;

	tmpind = 0;
	while (read(0, input, 1))
	{
		tmp[tmpind] = input[0];
		tmpind++;
		if (tmpind > 4)
			return (0);
		if (input[0] == '\n')
		{
			tmp[tmpind - 1] = '\0';
			ins_num = validate_instruction(tmp);
			if (ins_num < 0)
				return (0);
			execute_instruction(ins_num, stack_a, stack_b);
			tmpind = 0;
		}
	}
	if (tmpind > 0)
		return (0);
	return (1);
}
