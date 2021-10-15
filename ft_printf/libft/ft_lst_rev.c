/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:28:04 by nmustach          #+#    #+#             */
/*   Updated: 2021/09/12 15:04:46 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_rev(t_list **list)
{
	t_list	*tmpnext;
	t_list	*tmp2;

	if ((*list)->next != NULL)
	{
		tmpnext = (*list)->next;
		tmp2 = (*list);
		(*list)->next = NULL;
		(*list) = tmpnext;
		while ((*list)->next)
		{
			tmpnext = (*list)->next;
			(*list)->next = tmp2;
			tmp2 = (*list);
			(*list) = tmpnext;
		}
		(*list)->next = tmp2;
	}
}
