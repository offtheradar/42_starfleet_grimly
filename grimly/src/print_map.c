/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:34:47 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/13 12:56:44 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grimly.h"

void		print_maze(t_maze_info *info)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < info->num_row)
	{
		j = 0;
		while (j < info->num_col)
		{
			if (info->map[i][j] <= -1 && info->map[i][j] >= -4)
				ft_putchar(info->empty);
			else
				ft_putchar(info->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int			create_path(t_maze_info **info, int x, int y)
{
	if ((*info)->map[y][x] == U)
	{
		create_path(info, x, y + 1);
		(*info)->map[y][x] = (*info)->path;
	}
	if ((*info)->map[y][x] == L)
	{
		create_path(info, x + 1, y);
		(*info)->map[y][x] = (*info)->path;
	}
	if ((*info)->map[y][x] == R)
	{
		create_path(info, x - 1, y);
		(*info)->map[y][x] = (*info)->path;
	}
	if ((*info)->map[y][x] == D)
	{
		create_path(info, x, y - 1);
		(*info)->map[y][x] = (*info)->path;
	}
	return (((*info)->steps_counter)++);
}

void		backtrack_print(t_maze_info **info, int x, int y, t_queue *q)
{
	int counter;

	counter = create_path(info, x, y);
	print_maze(*info);
	ft_putstr("RESULT IN ");
	ft_putnbr(counter);
	ft_putstr(" STEPS!\n");
	free_queue(q);
	free(q);
}
