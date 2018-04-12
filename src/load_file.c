/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:56:35 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/11 19:34:31 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grimly.h"

/*
** Safely open the file
*/

int			open_file(char *file_name)
{
	int fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_putstr_fd("File Error!", 2);
		exit(0);
	}
	return (fd);
}

void		load_input_descriptor(char *buff, t_maze_info **maze)
{
	if (!((*maze)->row_size = ft_atoi(buff)) || (*maze)->row_size <= 0)
		map_error();
	while (ft_isdigit(*buff))
		buff++;
	if (*buff != 'x')
		map_error();
	buff++;
	if (!((*maze)->col_size = ft_atoi(buff)) || (*maze)->col_size <= 0)
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

int			verify_row(char *str, t_maze_info *info)
{
	int			i;
	static int	num_entries;
	static int	num_exit;
	static int	rows;

	i = -1;
	while (str[++i])
	{
		if (str[i] != info->empty && str[i] != info->start &&
			str[i] != info->end && str[i] != info->path && str[i] != info->full)
			map_error();
		if (str[i] == info->start)
		{
			num_entries += 1;
			info->start_point->x = i;
			info->start_point->y = rows;
		}
		if (str[i] == info->end)
			num_exit += 1;
		if (num_entries > 1)
			map_error();
	}
	if (++rows > info->row_size)
		map_error();
	return (num_exit);
}

t_maze_info	*load_file(int fd)
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
	free(buff);
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
