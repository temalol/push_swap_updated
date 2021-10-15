/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:12:35 by nmustach          #+#    #+#             */
/*   Updated: 2021/09/19 17:36:14 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tolower_str(char *str)
{
	size_t	i;
	size_t	str_size;
	char	*new_str;

	i = 0;
	str_size = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * (str_size));
	if (new_str == NULL)
		return (NULL);
	while (str[i])
	{
		new_str[i] = ft_tolower(str[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
