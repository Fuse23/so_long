/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:43:36 by falarm            #+#    #+#             */
/*   Updated: 2022/05/14 15:05:12 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	init_player(t_mapdata *mapdata, int i, int j)
{
	mapdata->player_psition_x = i;
	mapdata->player_psition_y = j;
	return (1);
}

void	init_enemy(t_mapdata *mapdata)
{
	int	i;
	int	j;

	i = 0;
	while (mapdata->map[i])
	{
		j = 0;
		while (mapdata->map[i][j])
		{
			if (mapdata->map[i][j] == 'X')
			{
				mapdata->enemy_position[mapdata->enemy].x = j;
				mapdata->enemy_position[mapdata->enemy].y = i;
				mapdata->enemy++;
			}
			j++;
		}
		i++;
	}
}
