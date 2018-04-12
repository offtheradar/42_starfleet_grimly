/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:54:09 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/11 20:44:56 by ysibous          ###   ########.fr       */
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

void	visit_adj(t_maze_info **info, int x, int y, t_queue *q, char prv)
{
	t_point *p;

	p = (t_point *)ft_memalloc(sizeof(t_point));
	(*info)->map[y][x] = prv;
	p->x = x;
	p->y = y;
	enqueue(q, p);
	free(p);
}

void	solve_map(t_maze_info **info)
{
	t_queue	q;
	t_point	*p;

	init_point(p, (*info)->start_point->x, (*info)->start_point->y);
	q = *(create_queue());
	enqueue(&q, p);
	while (q.front)
	{
		if (solution_found(*info, q.front))
		{
			backtrack_print(info, q.front->point->x, q.front->point->y);
			free_queue(&q);
			return ;
		}
		if (is_empty(q.front->point->y - 1, q.front->point->x, *info))
			visit_adj(info, q.front->point->x, q.front->point->y - 1, &q, '9');
		if (is_empty(q.front->point->y, q.front->point->x - 1, *info))
			visit_adj(info, q.front->point->x - 1, q.front->point->y, &q, '8');
		if (is_empty(q.front->point->y, q.front->point->x + 1, *info))
			visit_adj(info, q.front->point->x + 1, q.front->point->y, &q, '7');
		if (is_empty(q.front->point->y + 1, q.front->point->x, *info))
			visit_adj(info, q.front->point->x, q.front->point->y + 1, &q, '6');
		dequeue(&q);
	}
	map_error();
}
