/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:48:08 by nmustach          #+#    #+#             */
/*   Updated: 2021/09/12 15:17:42 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	char	*ptr;
	size_t	cnt;

	cnt = 0;
	ptr = (char *)(s);
	while (ptr[cnt])
	{
		cnt++;
	}
	return (cnt);
}
