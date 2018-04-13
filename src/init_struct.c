/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:31:03 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/12 17:49:18 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grimly.h"

void		init_maze_info(t_maze_info **info)
{
	*info = ft_memalloc(sizeof(t_maze_info));
	(*info)->num_col = 0;
	(*info)->num_row = 0;
	(*info)->empty = 0;
	(*info)->full = 0;
	(*info)->start = 0;
	(*info)->path = 0;
	(*info)->end = 0;
	(*info)->start_point = init_pt(0, 0);
}

t_point		*init_pt(int x, int y)
{
	t_point *p;

	p = (t_point *)ft_memalloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	return (p);
}

void		free_maze(t_maze_info *info)
{
	int i;

	i = 0;
	while (i < info->num_row)
	{
		free(info->map[i]);
		i++;
	}
	free(info->start_point);
	free(info->map);
	free(info);
}
