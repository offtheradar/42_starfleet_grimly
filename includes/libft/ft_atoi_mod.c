/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:18:28 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/10 17:24:24 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_mod(char **str)
{
	int sign;
	int output;
	int i;

	sign = 1;
	output = 0;
	i = 0;
	if (!(*str))
		return (0);
	while ((*str[i] == '\n' ||
			*str[i] == '\t' ||
			*str[i] == '\r' ||
			*str[i] == '\v' ||
			*str[i] == '\f' ||
			*str[i] == ' ') && *str[i])
		i++;
	if ((*str[i] == '+' || *str[i] == '-') && *str[i])
	{
		if (*str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(*(str[i])) && *str[i])
	{
		output = output * 10 + (*str[i] - '0');
		i++;
	}
	return (output * sign);
}
