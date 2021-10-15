/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:59:52 by nmustach          #+#    #+#             */
/*   Updated: 2021/10/15 20:49:25 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	validate_sign(const char *str, int *flag, int *i)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*flag = -1;
		*i = *i + 1;
		if (!str[*i])
			return (0);
	}
	return (1);
}

int	hangle_keys(char *argv)
{
	if (argv[0] == '-')
	{
		if (argv[1] == 'm')
			return (1);
	}
	return (0);
}
