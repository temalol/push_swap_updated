/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:14:06 by nmustach          #+#    #+#             */
/*   Updated: 2021/09/12 15:18:28 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int	len;
	int	cnt;

	len = 0;
	cnt = 0;
	len = ft_strlen(s1);
	while (n && s2[cnt])
	{
		s1[len] = s2[cnt];
		len++;
		cnt++;
		n--;
	}
	s1[len] = '\0';
	return (s1);
}
