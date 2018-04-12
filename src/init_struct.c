/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:31:03 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/11 20:45:27 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grimly.h"

void		init_maze_info(t_maze_info **new_maze)
{
	*new_maze = ft_memalloc(sizeof(t_maze_info));
	(*new_maze)->col_size = 0;
	(*new_maze)->row_size = 0;
	(*new_maze)->empty = 0;
	(*new_maze)->full = 0;
	(*new_maze)->start = 0;
	(*new_maze)->path = 0;
	(*new_maze)->end = 0;
	(*new_maze)->start_point = ft_memalloc(sizeof(t_point));
	(*new_maze)->start_point->x = 0;
	(*new_maze)->start_point->y = 0;
}

void		malloc_map(char ***str, int num_row, int num_col)
{
	int i;

	i = 0;
	*str = ft_memalloc(sizeof(char *) * num_row);
	while (i < num_row)
	{
		(*str)[i] = ft_memalloc(sizeof(char) * num_col);
		i++;
	}
}

void		init_point(t_point *p, int x, int y)
{
	p = (t_point *)ft_memalloc(sizeof(t_point));
	p->x = x;
	p->y = y;
}
