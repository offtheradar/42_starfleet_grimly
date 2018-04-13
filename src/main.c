/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:30:24 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/12 17:48:27 by ysibous          ###   ########.fr       */
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
	if (argc == 1)
	{
		info = load_file(fd);
		solve_map(&info);
	}
	else
	{
		while (argv[i])
		{
			fd = open_file(argv[1]);
			info = load_file(fd);
			solve_map(&info);
			i++;
		}
	}
	free_maze(info);
	return (0);
}
