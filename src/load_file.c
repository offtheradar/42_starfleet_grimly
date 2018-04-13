/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:56:35 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/13 13:38:33 by ysibous          ###   ########.fr       */
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

/* Load the information (col and row size, and chars for empty, path, full, start and end)
** of the first line of the file in the info struct;
** verifies whether the input is properly formatted.
*/

void		load_input_descriptor(char *buff, t_maze_info **info)
{
	if (!((*info)->num_row = ft_atoi(buff)) || (*info)->num_row <= 0)
		(*info)->error = -1;
	while (ft_isdigit(*buff))
		buff++;
	if (*buff != 'x')
		(*info)->error = -1;
	buff++;
	if (!((*info)->num_col = ft_atoi(buff)) || (*info)->num_col <= 0)
		(*info)->error = -1;
	while (ft_isdigit(*buff))
		buff++;
	if (ft_strlen(buff) != 5)
		(*info)->error = -1;
	(*info)->full = *(buff)++;
	(*info)->empty = *(buff)++;
	(*info)->path = *(buff)++;
	(*info)->start = *(buff)++;
	(*info)->end = *(buff);
}

/* This functions verifies the row that is read for any formatting violations,
 * i.e. more than one entry, or no exits, too many or not enough chars, and
 * detects whether there are too many rows.
*/

void		verify_row(char *str, t_maze_info *info)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != info->empty && str[i] != info->start &&
			str[i] != info->end && str[i] != info->path && str[i] != info->full)
			info->error = -1;
		if (str[i] == info->start)
		{
			info->entry_counter += 1;
			info->start_point->x = i;
			info->start_point->y = info->row_counter;
		}
		if (str[i] == info->end)
			info->exit_counter += 1;
		if (info->entry_counter > 1)
			info->error = -1;
	}
	if (++(info->row_counter) > info->num_row || info->num_col != i)
		info->error = -1;
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
	info->map = ft_memalloc(sizeof(char *) * info->num_row);
	while (get_next_line(fd, &(info->map[i])) > 0)
	{
		verify_row(info->map[i], info);
		i++;
	}
	if (!(info->exit_counter) || (info->row_counter) != info->num_row)
		(info)->error = -1;
	return (info);
}
