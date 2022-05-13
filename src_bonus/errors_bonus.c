/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:22:59 by falarm            #+#    #+#             */
/*   Updated: 2022/05/13 20:54:20 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_sprites(t_mapdata *mapdata)
{
	free(mapdata->sprites.collectible);
	free(mapdata->sprites.floor);
	free(mapdata->sprites.wall);
	free(mapdata->sprites.player1);
	free(mapdata->sprites.player2);
	free(mapdata->sprites.exit1);
	free(mapdata->sprites.exit0);
	free(mapdata->sprites.enemy1);
	free(mapdata->sprites.enemy2);
}

void	free_mapdata(t_mapdata *mapdata)
{
	int	i;

	i = -1;
	while (mapdata->map[++i])
		free(mapdata->map[i]);
	free(mapdata->map);
	free(mapdata);
}

void	ft_error(char *str, t_mapdata *mapdata)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	free_mapdata(mapdata);
	exit(EXIT_SUCCESS);
}

void	error_arg(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Example: ./so_long maps/1.ber\n", 2);
	exit(EXIT_SUCCESS);
}

void	error_fd(void)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
