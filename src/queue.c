/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:05:55 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/11 10:28:24 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grimly.h"

/*
** Function to reate a new queue list node
*/

t_qnode	*new_node(t_point *pt)
{
	t_qnode *tmp = (t_qnode *)ft_memalloc(sizeof(t_qnode));
	tmp->point = (t_point *)ft_memalloc(sizeof(t_point));
	tmp->point->x = pt->x;
	tmp->point->y = pt->y;
	tmp->next = NULL;
	return (tmp);
}

/*
** Function to create an empty queue
*/

t_queue	*create_queue(void)
{
	t_queue *q = (t_queue *)ft_memalloc(sizeof(t_queue));
	q->front = NULL;
	q->rear = NULL;
	return (q);
}

/*
** Function to add a point to the queue
*/

void	enqueue(t_queue *q, t_point *pt)
{
	t_qnode	*tmp;
	
	tmp = new_node(pt);
	if (q->rear == NULL)
	{
		q->front = tmp;
		q->rear = tmp;
		return ;
	}
	q->rear->next = tmp;
	q->rear = tmp;
}

/*
** Function to remove, and return the first element in the queue (FIFO)
*/

t_qnode		*dequeue(t_queue *q)
{
	t_qnode *tmp;

	if (!q->front)
		return (NULL);
	tmp = q->front;
	q->front = q->front->next;
	if (!q->front)
		q->rear = NULL;
	return (tmp);
}
