/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:56:25 by nmustach          #+#    #+#             */
/*   Updated: 2021/09/12 15:16:07 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char	*s;
	int		cnt;

	cnt = 0;
	s = (char *)(src);
	while (s[cnt])
	{
		dst[cnt] = s[cnt];
		cnt++;
	}
	dst[cnt] = '\0';
	return (dst);
}
