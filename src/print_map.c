/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:34:47 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/11 10:35:22 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grimly.h"

void		print_maze(t_maze_info *info)
{
	int i;

	i = 0;
	while (i < info->row_size)
	{
		ft_putstr(info->map[i]);
		ft_putstr("\n");
		i++;
	}
}
