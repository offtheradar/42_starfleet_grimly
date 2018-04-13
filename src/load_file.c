/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:56:35 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/12 17:51:59 by ysibous          ###   ########.fr       */
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

void		load_input_descriptor(char *buff, t_maze_info **info)
{
	if (!((*info)->num_row = ft_atoi(buff)) || (*info)->num_row <= 0)
		map_error();
	while (ft_isdigit(*buff))
		buff++;
	if (*buff != 'x')
		map_error();
	buff++;
	if (!((*info)->num_col = ft_atoi(buff)) || (*info)->num_col <= 0)
		map_error();
	while (ft_isdigit(*buff))
		buff++;
	if (ft_strlen(buff) != 5)
		map_error();
	(*info)->full = *(buff)++;
	(*info)->empty = *(buff)++;
	(*info)->path = *(buff)++;
	(*info)->start = *(buff)++;
	(*info)->end = *(buff);
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
	if (++rows > info->num_row)
		map_error();
	return (num_exit);
}

t_maze_info	*load_file(int fd)
{
	t_maze_info *info;
	int			num_exit;
	int			i;
	char		*buff;

	i = 0;
	num_exit = 0;
	init_maze_info(&info);
	get_next_line(fd, &buff);
	load_input_descriptor(buff, &info);
	free(buff);
	info->map = ft_memalloc(sizeof(char *) *info->num_row);
	while (get_next_line(fd, &(info->map[i])) > 0)
	{
		num_exit = verify_row(info->map[i], info);
		i++;
	}
	if (!num_exit)
		map_error();
	return (info);
}
