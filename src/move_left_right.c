/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:06:24 by falarm            #+#    #+#             */
/*   Updated: 2022/04/21 20:28:30 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	left(t_mapdata *mapdata)
{
	mapdata->map[mapdata->player_psition_x][mapdata->player_psition_y - 1] = 'P';
	mapdata->map[mapdata->player_psition_x][mapdata->player_psition_y] = '0';
	mapdata->player_psition_y--;
	steps(mapdata);
}

void	right(t_mapdata *mapdata)
{
	mapdata->map[mapdata->player_psition_x][mapdata->player_psition_y + 1] = 'P';
	mapdata->map[mapdata->player_psition_x][mapdata->player_psition_y] = '0';
	mapdata->player_psition_y++;
	steps(mapdata);
}

void	move_left(t_mapdata *mapdata)
{
	if (mapdata->map[mapdata->player_psition_x][mapdata->player_psition_y - 1] == '0')
		left(mapdata);
	else if (mapdata->map[mapdata->player_psition_x][mapdata->player_psition_y - 1] == 'C')
	{
		left(mapdata);
		mapdata->curent_score++;
	}
	else if (mapdata->map[mapdata->player_psition_x][mapdata->player_psition_y - 1] == 'E'
			&& mapdata->curent_score == mapdata->score)
			end(mapdata);
}

void	move_right(t_mapdata *mapdata)
{
	if (mapdata->map[mapdata->player_psition_x][mapdata->player_psition_y + 1] == '0')
		left(mapdata);
	else if (mapdata->map[mapdata->player_psition_x][mapdata->player_psition_y + 1] == 'C')
	{
		left(mapdata);
		mapdata->curent_score++;
	}
	else if (mapdata->map[mapdata->player_psition_x][mapdata->player_psition_y + 1] == 'E'
			&& mapdata->curent_score == mapdata->score)
			end(mapdata);
}
