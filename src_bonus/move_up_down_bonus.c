/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_down_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:05:57 by falarm            #+#    #+#             */
/*   Updated: 2022/05/13 20:10:44 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	up(t_mapdata *mapdata)
{
	mapdata->map[mapdata->player_psition_x - 1] \
	[mapdata->player_psition_y] = 'P';
	mapdata->map[mapdata->player_psition_x] \
	[mapdata->player_psition_y] = '0';
	mapdata->player_psition_x--;
	mapdata->steps++;
}

void	down(t_mapdata *mapdata)
{
	mapdata->map[mapdata->player_psition_x + 1] \
	[mapdata->player_psition_y] = 'P';
	mapdata->map[mapdata->player_psition_x] \
	[mapdata->player_psition_y] = '0';
	mapdata->player_psition_x++;
	mapdata->steps++;
}

void	move_up(t_mapdata *mapdata)
{
	if (mapdata->map[mapdata->player_psition_x - 1] \
	[mapdata->player_psition_y] == '0')
		up(mapdata);
	else if (mapdata->map[mapdata->player_psition_x - 1] \
	[mapdata->player_psition_y] == 'C')
	{
		up(mapdata);
		mapdata->curent_score++;
	}
	else if (mapdata->map[mapdata->player_psition_x - 1] \
	[mapdata->player_psition_y] == 'E'
		&& mapdata->curent_score == mapdata->score)
		end(mapdata);
	else if (mapdata->map[mapdata->player_psition_x - 1] \
	[mapdata->player_psition_y] == 'X')
		end(mapdata);
}

void	move_down(t_mapdata *mapdata)
{
	if (mapdata->map[mapdata->player_psition_x + 1] \
	[mapdata->player_psition_y] == '0')
		down(mapdata);
	else if (mapdata->map[mapdata->player_psition_x + 1] \
	[mapdata->player_psition_y] == 'C')
	{
		down(mapdata);
		mapdata->curent_score++;
	}
	else if (mapdata->map[mapdata->player_psition_x + 1] \
	[mapdata->player_psition_y] == 'E'
		&& mapdata->curent_score == mapdata->score)
		end(mapdata);
	else if (mapdata->map[mapdata->player_psition_x + 1] \
	[mapdata->player_psition_y] == 'X')
		end(mapdata);
}
