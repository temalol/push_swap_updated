/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:16:39 by nmustach          #+#    #+#             */
/*   Updated: 2021/09/12 15:15:55 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			cnt;
	unsigned char	*str1;
	unsigned char	*str2;

	cnt = 0;
	str1 = (unsigned char *)(s1);
	str2 = (unsigned char *)(s2);
	while (n--)
	{
		if (str1[cnt] == str2[cnt] && str1[cnt] && str2[cnt])
			cnt++;
		else
			return (str1[cnt] - str2[cnt]);
	}
	return (0);
}
