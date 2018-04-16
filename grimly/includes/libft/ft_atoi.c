/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:09:26 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/12 11:00:43 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int sign;
	int output;

	sign = 1;
	output = 0;
	if (!str)
		return (0);
	while ((*str == '\n' || *str == '\t' || *str == '\r' || *str == '\v' ||
			*str == '\f' ||
			*str == ' ') && *str)
		str++;
	if ((*str == '+' || *str == '-') && *str)
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str) && *str)
	{
		output = output * 10 + (*str - '0');
		str++;
	}
	return (output * sign);
}
