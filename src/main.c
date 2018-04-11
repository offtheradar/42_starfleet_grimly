/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:30:24 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/11 10:30:38 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/grimly.h"

int main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		map_error();
	fd = open_file(argv[1]);
	print_maze(load_file(fd));
	return (0);
}
