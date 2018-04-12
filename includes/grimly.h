/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:55:04 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/12 11:01:49 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H
# include "libft/libft.h"

typedef	struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_qnode
{
	t_point			*point;
	struct s_qnode	*next;
}				t_qnode;

typedef struct	s_queue
{
	struct s_qnode *front;
	struct s_qnode *rear;
}				t_queue;

typedef struct	s_maze_info
{
	int		col_size;
	int		row_size;
	char	empty;
	char	full;
	char	start;
	char	path;
	char	end;
	t_point *start_point;
	char	**map;
}				t_maze_info;

t_qnode			*new_node(t_point *pt);

t_queue			*create_queue(void);

t_point			*init_point(int x, int y);

void			enqueue(t_queue *q, t_point *pt);

void			dequeue(t_queue *q);

void			free_queue(t_queue *q);

int				open_file(char *file_name);

void			init_maze_info(t_maze_info **new_maze);

void			map_error(void);

void			load_input_descriptor(char *buff, t_maze_info **maze);

int				verify_row(char *str, t_maze_info *info);

void			malloc_map(char ***str, int num_row, int num_col);

t_maze_info		*load_file(int fd);

void			print_maze(t_maze_info *info);

int				is_valid_pt(int x, int y, t_maze_info *info);

int				solution_found(t_maze_info *info, t_qnode *q);

int				is_empty(int x, int y, t_maze_info *info);

int				create_path(t_maze_info **info, int x, int y);

void			backtrack_print(t_maze_info **info, int x, int y);

void			solve_map(t_maze_info **info);

#endif
