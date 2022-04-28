/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:37:08 by falarm            #+#    #+#             */
/*   Updated: 2022/04/28 18:23:01 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_map(t_mapdata *mapdata, int i, int j)
{
	if (mapdata->map[i][j] == '1')
		mlx_put_image_to_window(mapdata->ptr.mlx, mapdata->ptr.win, \
		mapdata->sprites.wall, j * SPRITE_Y, i * SPRITE_X);
	else if (mapdata->map[i][j] == '0')
		mlx_put_image_to_window(mapdata->ptr.mlx, mapdata->ptr.win, \
		mapdata->sprites.floor, j * SPRITE_Y, i * SPRITE_X);
	else if (mapdata->map[i][j] == 'C')
		mlx_put_image_to_window(mapdata->ptr.mlx, mapdata->ptr.win, \
		mapdata->sprites.collectible, j * SPRITE_Y, i * SPRITE_X);
	else if (mapdata->map[i][j] == 'E')
		mlx_put_image_to_window(mapdata->ptr.mlx, mapdata->ptr.win, \
		mapdata->sprites.exit1, j * SPRITE_Y, i * SPRITE_X);
	else if (mapdata->map[i][j] == 'P')
		mlx_put_image_to_window(mapdata->ptr.mlx, mapdata->ptr.win, \
		mapdata->sprites.player1, j * SPRITE_Y, i * SPRITE_X);
}

int	draw(t_mapdata *mapdata)
{
	int	i;
	int	j;

	i = -1;
	while (mapdata->map[++i])
	{
		j = -1;
		while (mapdata->map[i][++j])
			draw_map(mapdata, i, j);
	}
	return (0);
}

int	keys(int key, t_mapdata *mapdata)
{
	if (key == UP)
		move_up(mapdata);
	else if (key == DOWN)
		move_down(mapdata);
	else if (key == LEFT)
		move_left(mapdata);
	else if (key == RIGHT)
		move_right(mapdata);
	else if (key == ESC)
		end(mapdata);
	draw(mapdata);
	return (0);
}

int	end(t_mapdata *mapdata)
{
	ft_putendl_fd("End game", 1);
	free_mapdata(mapdata);
	exit(EXIT_SUCCESS);
	return (0);
}

void	steps(t_mapdata *mapdata)
{
	mapdata->steps++;
	ft_putnbr_fd(mapdata->steps, 1);
	ft_putstr_fd("\n", 1);
}
