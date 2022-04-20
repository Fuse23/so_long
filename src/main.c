/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:41:18 by falarm            #+#    #+#             */
/*   Updated: 2022/04/20 21:37:57 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_mapdata	*parsing_map(int argc, char **argv)
{
	t_mapdata	*mapdata;
	char		*map_in_line;

	check_args(argc, argv);
	map_in_line = get_map_in_line(argv);
	mapdata = init_mapdata(map_in_line);
	check_map_whole(mapdata, argv);
	check_map_line(mapdata);
	check_map_arg(mapdata, -1, -1);
	check_map_border(mapdata, -1, -1);
	return (mapdata);
}

int	main(int argc, char **argv)
{
	t_mapdata	*mapdata;

	mapdata = parsing_map(argc, argv);
	return (0);
}
