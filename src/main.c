/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:30:24 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/13 14:14:27 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grimly.h"

int	main(int argc, char **argv)
{
	int			fd;
	int			i;
	t_maze_info	*info;

	fd = 0;
	i = 1;
	while (argv[i])
	{
		if (argc != 1)
			fd = open_file(argv[i]);
		info = load_file(fd);
		if (info->error == -1)
			ft_putstr_fd("MAP ERROR\n", 2);
		else
			solve_map(&info);
		if (info->error == -2)
			ft_putstr_fd("MAP ERROR\n", 2);
		i++;
	}
	free_maze(info);
	return (0);
}
