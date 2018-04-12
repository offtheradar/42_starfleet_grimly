/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:34:47 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/11 18:11:32 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grimly.h"

void		print_maze(t_maze_info *info)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < info->row_size)
	{
		j = 0;
		while (j < info->col_size)
		{
//			if (info->map[i][j] <= '9' && info->map[i][j] >= '6')
//				ft_putchar(info->empty);
//			else
				ft_putchar(info->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
