/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:55:04 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/10 19:14:30 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
#define GRIMLY_H

#include "libft/libft.h"

typedef	struct	s_point
{
	int x;
	int y;
}				t_point;

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
#endif
