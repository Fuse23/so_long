/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:41:18 by falarm            #+#    #+#             */
/*   Updated: 2022/05/13 20:46:33 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	play(t_mapdata *mapdata)
{
	mlx_hook(mapdata->ptr.win, 2, 0, keys, mapdata);
	mlx_hook(mapdata->ptr.win, 17, 0, end, mapdata);
	mlx_loop_hook(mapdata->ptr.mlx, draw, mapdata);
	mlx_loop(mapdata->ptr.mlx);
}

t_mapdata	*parsing_map(int argc, char **argv)
{
	t_mapdata	*mapdata;
	char		*map_in_line;

	check_args(argc, argv);
	map_in_line = get_map_in_line(argv);
	mapdata = init_mapdata(map_in_line);
	init_sprites(mapdata);
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
	play(mapdata);
	free_mapdata(mapdata);
	// check_leaks();
	return (0);
}
