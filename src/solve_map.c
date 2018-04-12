/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:54:09 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/11 18:24:21 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grimly.h"


int		is_valid_pt(int y, int x, t_maze_info *info)
{
	if (x >= 0 && y >= 0 && x < info->col_size && y < info->row_size)
		return (1);
	return (0);
}

int		solution_found(t_maze_info *info, t_qnode *q)
{
	if ((is_valid_pt(q->point->y + 1, q->point->x, info) &&
		info->map[q->point->y + 1][q->point->x] == info->end) ||
		(is_valid_pt(q->point->y - 1, q->point->x, info) &&
		info->map[q->point->y - 1][q->point->x] == info->end) ||
		(is_valid_pt(q->point->y, q->point->x + 1, info) &&
		info->map[q->point->y][q->point->x + 1] == info->end) ||
		(is_valid_pt(q->point->y, q->point->x - 1, info) &&
		info->map[q->point->y][q->point->x - 1] == info->end))
		return (1);
	return (0);
}

int		is_empty(int y, int x, t_maze_info *info)
{
	if (is_valid_pt(y, x, info) && info->map[y][x] == info->empty)
		return (1);
	return (0);
}

void	create_path(t_maze_info **info, int x, int y)
{
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
}

void	backtrack_print(t_maze_info **info, int x, int y, int counter)
{
	create_path(info, x, y);
	print_maze(*info);
	ft_putnbr(counter);
}

void	solve_map(t_maze_info **info)
{
	t_queue	q;
	t_point	*p;
	int counter;

	p = (t_point *)ft_memalloc(sizeof(t_point));
	p->x = (*info)->start_point->x;
	p->y = (*info)->start_point->y;
	q = *(create_queue());
	enqueue(&q, p);
	counter = 0;
	while (q.front)
	{
		if (solution_found(*info, q.front))
		{
			backtrack_print(info, q.front->point->x, q.front->point->y, counter);
			return ;
		}
		if (is_empty(q.front->point->y - 1, q.front->point->x, *info))
		{
			(*info)->map[q.front->point->y - 1][q.front->point->x] = '9';
			p->x = q.front->point->x;
			p->y = q.front->point->y - 1;
			enqueue(&q, p);
		}
		if (is_empty(q.front->point->y, q.front->point->x - 1, *info))
		{
			(*info)->map[q.front->point->y][q.front->point->x - 1] = '8';
			p->x = q.front->point->x - 1;
			p->y = q.front->point->y;
			enqueue(&q, p);
		}
		if (is_empty(q.front->point->y, q.front->point->x + 1, *info))
		{
			(*info)->map[q.front->point->y][q.front->point->x + 1] = '7';
			p->x = q.front->point->x + 1;
			p->y = q.front->point->y;
			enqueue(&q, p);
		}
		if (is_empty(q.front->point->y + 1, q.front->point->x, *info))
		{
			(*info)->map[q.front->point->y + 1][q.front->point->x] = '6';
			p->x = q.front->point->x;
			p->y = q.front->point->y + 1;
			enqueue(&q, p);
		}
		counter += 1;
		//print_maze(*info);
		dequeue(&q);
	}
	map_error();
}
