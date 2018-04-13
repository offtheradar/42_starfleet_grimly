/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:55:04 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/13 13:18:48 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H
# include "libft/libft.h"
# define U -1
# define L -2
# define R -3
# define D -4

typedef	struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_qnode
{
	t_point			*pt;
	struct s_qnode	*next;
}				t_qnode;

typedef struct	s_queue
{
	struct s_qnode *front;
	struct s_qnode *rear;
}				t_queue;

typedef struct	s_maze_info
{
	int		num_col;
	int		num_row;
	int		row_counter;
	int		entry_counter;
	int		exit_counter;
	int		steps_counter;
	int		error;
	char	empty;
	char	full;
	char	start;
	char	path;
	char	end;
	t_point *start_point;
	char	**map;
}				t_maze_info;

void			free_maze(t_maze_info *info);

t_qnode			*new_node(t_point *pt);

t_queue			*create_queue(void);

t_point			*init_pt(int x, int y);

void			enqueue(t_queue *q, t_point *pt);

void			dequeue(t_queue *q);

void			free_queue(t_queue *q);

int				open_file(char *file_name);

void			init_maze_info(t_maze_info **new_maze);

int				map_error(void);

void			load_input_descriptor(char *buff, t_maze_info **maze);

void			verify_row(char *str, t_maze_info *info);

t_maze_info		*load_file(int fd);

void			print_maze(t_maze_info *info);

int				is_valid_pt(int x, int y, t_maze_info *info);

int				solution_found(t_maze_info *info, t_qnode *q);

int				is_empty(int x, int y, t_maze_info *info);

int				create_path(t_maze_info **info, int x, int y);

void			backtrack_print(t_maze_info **info, int x, int y, t_queue *q);

void			solve_map(t_maze_info **info);

#endif
