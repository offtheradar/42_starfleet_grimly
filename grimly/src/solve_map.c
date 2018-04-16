/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:54:09 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/15 18:38:54 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grimly.h"

int		is_valid_pt(int y, int x, t_maze_info *info)
{
	if (x >= 0 && y >= 0 && x < info->num_col && y < info->num_row)
		return (1);
	return (0);
}

int		solution_found(t_maze_info *info, t_qnode *q)
{
	if ((is_valid_pt(q->pt->y + 1, q->pt->x, info) &&
		info->map[q->pt->y + 1][q->pt->x] == info->end) ||
		(is_valid_pt(q->pt->y - 1, q->pt->x, info) &&
		info->map[q->pt->y - 1][q->pt->x] == info->end) ||
		(is_valid_pt(q->pt->y, q->pt->x + 1, info) &&
		info->map[q->pt->y][q->pt->x + 1] == info->end) ||
		(is_valid_pt(q->pt->y, q->pt->x - 1, info) &&
		info->map[q->pt->y][q->pt->x - 1] == info->end))
		return (1);
	return (0);
}

int		is_empty(int y, int x, t_maze_info *info)
{
	if (is_valid_pt(y, x, info) && info->map[y][x] == info->empty)
		return (1);
	return (0);
}

void	vis_adj(t_maze_info **info, t_point *p, t_queue *q, char prv)
{
	(*info)->map[p->y][p->x] = prv;
	enqueue(q, p);
	free(p);
}

void	solve_map(t_maze_info **info)
{
	t_queue	*q;
	t_point	*p;

	p = init_pt((*info)->start_point->x, (*info)->start_point->y);
	q = (create_queue());
	enqueue(q, p);
	free(p);
	while (q->front)
	{
		if (solution_found(*info, q->front))
			return (backtrack_print(info, q->front->pt->x, q->front->pt->y, q));
		if (is_empty(q->front->pt->y - 1, q->front->pt->x, *info))
			vis_adj(info, init_pt(q->front->pt->x, q->front->pt->y - 1), q, U);
		if (is_empty(q->front->pt->y, q->front->pt->x - 1, *info))
			vis_adj(info, init_pt(q->front->pt->x - 1, q->front->pt->y), q, L);
		if (is_empty(q->front->pt->y, q->front->pt->x + 1, *info))
			vis_adj(info, init_pt(q->front->pt->x + 1, q->front->pt->y), q, R);
		if (is_empty(q->front->pt->y + 1, q->front->pt->x, *info))
			vis_adj(info, init_pt(q->front->pt->x, q->front->pt->y + 1), q, D);
		dequeue(q);
	}
	free(q);
	(*info)->error = -2;
}
