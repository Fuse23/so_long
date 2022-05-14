/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:05:57 by falarm            #+#    #+#             */
/*   Updated: 2022/05/14 15:02:11 by falarm           ###   ########.fr       */
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
	steps(mapdata);
}

void	down(t_mapdata *mapdata)
{
	mapdata->map[mapdata->player_psition_x + 1] \
	[mapdata->player_psition_y] = 'P';
	mapdata->map[mapdata->player_psition_x] \
	[mapdata->player_psition_y] = '0';
	mapdata->player_psition_x++;
	steps(mapdata);
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
		end();
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
		end();
}
