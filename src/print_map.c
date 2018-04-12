/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:34:47 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/11 20:07:39 by ysibous          ###   ########.fr       */
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
			if (info->map[i][j] <= '9' && info->map[i][j] >= '6')
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
	static int counter;

	if ((*info)->map[y][x] == '9')
	{
		create_path(info, x, y + 1);
		(*info)->map[y][x] = (*info)->path;
	}
	if ((*info)->map[y][x] == '8')
	{
		create_path(info, x + 1, y);
		(*info)->map[y][x] = (*info)->path;
	}
	if ((*info)->map[y][x] == '7')
	{
		create_path(info, x - 1, y);
		(*info)->map[y][x] = (*info)->path;
	}
	if ((*info)->map[y][x] == '6')
	{
		create_path(info, x, y - 1);
		(*info)->map[y][x] = (*info)->path;
	}
	counter++;
	return (counter);
}

void		backtrack_print(t_maze_info **info, int x, int y)
{
	int counter;

	counter = create_path(info, x, y);
	print_maze(*info);
	ft_putstr("RESULT IN ");
	ft_putnbr(counter);
	ft_putstr(" STEPS!\n");
}
