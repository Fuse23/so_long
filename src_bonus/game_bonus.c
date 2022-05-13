/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:37:08 by falarm            #+#    #+#             */
/*   Updated: 2022/05/13 20:58:22 by falarm           ###   ########.fr       */
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
		mapdata->sprites.exit, j * SPRITE_Y, i * SPRITE_X);
	else if (mapdata->map[i][j] == 'P')
		mlx_put_image_to_window(mapdata->ptr.mlx, mapdata->ptr.win, \
		mapdata->sprites.player, j * SPRITE_Y, i * SPRITE_X);
	else if (mapdata->map[i][j] == 'X')
		mlx_put_image_to_window(mapdata->ptr.mlx, mapdata->ptr.win, \
		mapdata->sprites.enemy, j * SPRITE_Y, i * SPRITE_X);
}

void	animation(t_mapdata *mapdata)
{
	enemy_move(mapdata);
	if (mapdata->sprites.player == mapdata->sprites.player1)
		mapdata->sprites.player = mapdata->sprites.player2;
	else if (mapdata->sprites.player == mapdata->sprites.player2)
		mapdata->sprites.player = mapdata->sprites.player1;
	if (mapdata->sprites.enemy == mapdata->sprites.enemy1)
		mapdata->sprites.enemy = mapdata->sprites.enemy2;
	else if (mapdata->sprites.enemy == mapdata->sprites.enemy2)
		mapdata->sprites.enemy = mapdata->sprites.enemy1;
	if (mapdata->score == mapdata->curent_score)
		mapdata->sprites.exit = mapdata->sprites.exit0;
}

int	draw(t_mapdata *mapdata)
{
	static int	k;
	int			i;
	int			j;
	char		*count;

	k++;
	if (k > 35)
	{
		animation(mapdata);
		k = 0;
	}
	count = ft_itoa(mapdata->steps);
	i = -1;
	while (mapdata->map[++i])
	{
		j = -1;
		while (mapdata->map[i][++j])
			draw_map(mapdata, i, j);
	}
	mlx_string_put(mapdata->ptr.mlx, mapdata->ptr.win, \
	10, 10, 0xff00, "Steps:");
	mlx_string_put(mapdata->ptr.mlx, mapdata->ptr.win, 75, 10, 0xff00, count);
	free(count);
	return (0);
}

int	keys(int key, t_mapdata *mapdata)
{
	if (key == UP || key == 126)
		move_up(mapdata);
	else if (key == DOWN | key == 125)
		move_down(mapdata);
	else if (key == LEFT | key == 123)
		move_left(mapdata);
	else if (key == RIGHT | key == 124)
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
