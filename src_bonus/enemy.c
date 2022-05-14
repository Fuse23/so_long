/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:07:49 by falarm            #+#    #+#             */
/*   Updated: 2022/05/14 15:03:32 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	enemy_move_up(t_mapdata *mapdata)
{
	int	i;

	i = -1;
	while (++i < mapdata->enemy)
	{
		if (mapdata->map[mapdata->enemy_position[i].y - 1] \
		[mapdata->enemy_position[i].x] == '0')
		{
			mapdata->map[mapdata->enemy_position[i].y - 1] \
			[mapdata->enemy_position[i].x] = 'X';
			mapdata->map[mapdata->enemy_position[i].y] \
			[mapdata->enemy_position[i].x] = '0';
			mapdata->enemy_position[i].y--;
		}
		else if (mapdata->map[mapdata->enemy_position[i].y - 1] \
		[mapdata->enemy_position[i].x] == 'P')
			end();
	}
}

void	enemy_move_down(t_mapdata *mapdata)
{
	int	i;

	i = -1;
	while (++i < mapdata->enemy)
	{
		if (mapdata->map[mapdata->enemy_position[i].y + 1] \
		[mapdata->enemy_position[i].x] == '0')
		{
			mapdata->map[mapdata->enemy_position[i].y + 1] \
			[mapdata->enemy_position[i].x] = 'X';
			mapdata->map[mapdata->enemy_position[i].y] \
			[mapdata->enemy_position[i].x] = '0';
			mapdata->enemy_position[i].y++;
		}
		else if (mapdata->map[mapdata->enemy_position[i].y + 1] \
		[mapdata->enemy_position[i].x] == 'P')
			end();
	}
}

void	enemy_move_left(t_mapdata *mapdata)
{
	int	i;

	i = -1;
	while (++i < mapdata->enemy)
	{
		if (mapdata->map[mapdata->enemy_position[i].y] \
		[mapdata->enemy_position[i].x - 1] == '0')
		{
			mapdata->map[mapdata->enemy_position[i].y] \
			[mapdata->enemy_position[i].x - 1] = 'X';
			mapdata->map[mapdata->enemy_position[i].y] \
			[mapdata->enemy_position[i].x] = '0';
			mapdata->enemy_position[i].x--;
		}
		else if (mapdata->map[mapdata->enemy_position[i].y] \
		[mapdata->enemy_position[i].x - 1] == 'P')
			end();
	}
}

void	enemy_move_right(t_mapdata *mapdata)
{
	int	i;

	i = -1;
	while (++i < mapdata->enemy)
	{
		if (mapdata->map[mapdata->enemy_position[i].y] \
		[mapdata->enemy_position[i].x + 1] == '0')
		{
			mapdata->map[mapdata->enemy_position[i].y] \
			[mapdata->enemy_position[i].x + 1] = 'X';
			mapdata->map[mapdata->enemy_position[i].y] \
			[mapdata->enemy_position[i].x] = '0';
			mapdata->enemy_position[i].x++;
		}
		else if (mapdata->map[mapdata->enemy_position[i].y] \
		[mapdata->enemy_position[i].x + 1] == 'P')
			end();
	}
}

void	enemy_move(t_mapdata *mapdata)
{
	int	i;

	i = rand() % 4;
	if (i == 0)
		enemy_move_up(mapdata);
	if (i == 1)
		enemy_move_down(mapdata);
	if (i == 2)
		enemy_move_left(mapdata);
	if (i == 3)
		enemy_move_right(mapdata);
}
