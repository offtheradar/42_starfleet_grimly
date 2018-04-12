/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:56:35 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/11 17:17:31 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grimly.h"

/*
** Safely open the file
*/

int		open_file(char *file_name)
{
	int fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_putstr("File Error!");
		exit(0);
	}
	return (fd);
}

void	init_maze_info(t_maze_info **new_maze)
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

void	map_error(void)
{
	ft_putstr("MAP ERROR\n");
	exit(1);
}

void	load_input_descriptor(char *buff, t_maze_info **maze)
{
	if (!((*maze)->row_size = ft_atoi(buff)))
		map_error();
	while (ft_isdigit(*buff))
		buff++;
	if (*buff != 'x')
		map_error();
	buff++;
	if (!((*maze)->col_size = ft_atoi(buff)))
		map_error();
	while (ft_isdigit(*buff))
		buff++;
	if (ft_strlen(buff) != 5)
		map_error();
	(*maze)->full = *(buff)++;
	(*maze)->empty = *(buff)++;
	(*maze)->path = *(buff)++;
	(*maze)->start = *(buff)++;
	(*maze)->end = *(buff);
}

#include <stdio.h>
int		verify_row(char *str, t_maze_info *info)
{
	int			i;
	static int	num_entries;
	static int	num_exit;
	static int	rows;

	i = 0;
	while (str[i])
	{
		if (str[i] != info->empty && str[i] != info->start &&
			str[i] != info->end && str[i] != info->path && str[i] != info->full)
			map_error();
		if (str[i] == info->start)
		{
			num_entries += 1;
			info->start_point->x = i;
			info->start_point->y = rows;
			printf("x is %d and y is %d\n", i, rows);
		}
		if (str[i] == info->end)
			num_exit += 1;
		if (num_entries > 1)
			map_error();
		i++;
	}
	if (++rows > info->row_size)
		map_error();
	return (num_exit);
}

void	malloc_map(char ***str, int num_row, int num_col)
{
	int i;

	i = 0;
	*str  = ft_memalloc(sizeof(char *) * num_row);
	while (i < num_row)
	{
		(*str)[i] = ft_memalloc(sizeof(char) * num_col);
		i++;
	}
}

t_maze_info		*load_file(int fd)
{
	t_maze_info *maze;
	int			num_exit;
	int			i;
	char		*buff;

	i = 0;
	num_exit = 0;
	init_maze_info(&maze);
	get_next_line(fd, &buff);
	load_input_descriptor(buff, &maze);
	malloc_map(&maze->map, maze->row_size, maze->col_size);
	while (get_next_line(fd, &(maze->map[i])) > 0)
	{
		num_exit = verify_row(maze->map[i], maze);
		i++;
	}
	if (!num_exit)
		map_error();
	return (maze);
}
