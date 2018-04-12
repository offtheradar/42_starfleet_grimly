/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:30:24 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/11 19:41:00 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grimly.h"

int	main(int argc, char **argv)
{
	int			fd;
	int			i;
	t_maze_info	*maze;

	fd = 0;
	i = 1;
	if (argc == 1)
	{
		maze = load_file(fd);
		solve_map(&maze);
	}
	else
	{
		while (argv[i])
		{
			fd = open_file(argv[1]);
			maze = load_file(fd);
			solve_map(&maze);
			i++;
		}
	}
	return (0);
}
