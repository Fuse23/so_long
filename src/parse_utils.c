/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:26:45 by falarm            #+#    #+#             */
/*   Updated: 2022/05/13 20:51:49 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*get_map_in_line(char **av)
{
	int		fd;
	char	*new_line;
	char	*line;
	char	*tmp;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_fd();
	new_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = new_line;
		new_line = ft_gnl_strjoin(new_line, line);
		free(tmp);
		free(line);
	}
	close(fd);
	return (new_line);
}

t_mapdata	*init_mapdata(char *line)
{
	t_mapdata	*mapdata;
	int			i;

	mapdata = malloc(sizeof(t_mapdata));
	if (!mapdata)
		return (NULL);
	mapdata->map = ft_split(line, '\n');
	if (!mapdata->map[0])
	{
		ft_putendl_fd("Error: map", 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (mapdata->map[i])
		i++;
	mapdata->width = ft_strlen(mapdata->map[0]);
	mapdata->hight = i;
	mapdata->score = 0;
	mapdata->curent_score = 0;
	mapdata->steps = 0;
	mapdata->ptr.mlx = mlx_init();
	mapdata->ptr.win = mlx_new_window(mapdata->ptr.mlx, \
	mapdata->width * SPRITE_X, mapdata->hight * SPRITE_Y, "so_long");
	free(line);
	return (mapdata);
}

int	init_player(t_mapdata *mapdata, int i, int j)
{
	mapdata->player_psition_x = i;
	mapdata->player_psition_y = j;
	return (1);
}

void	init_sprites(t_mapdata *mapdata)
{
	int	x;
	int	y;

	x = SPRITE_X;
	y = SPRITE_Y;
	mapdata->sprites.wall = mlx_xpm_file_to_image \
	(mapdata->ptr.mlx, WALL, &x, &y);
	mapdata->sprites.floor = mlx_xpm_file_to_image \
	(mapdata->ptr.mlx, FLOOR, &x, &y);
	mapdata->sprites.player1 = mlx_xpm_file_to_image \
	(mapdata->ptr.mlx, PLAYER1, &x, &y);
	mapdata->sprites.exit1 = mlx_xpm_file_to_image \
	(mapdata->ptr.mlx, EXIT1, &x, &y);
	mapdata->sprites.collectible = mlx_xpm_file_to_image \
	(mapdata->ptr.mlx, COLLECTIBLE, &x, &y);
	if (!mapdata->sprites.wall || !mapdata->sprites.floor
		|| !mapdata->sprites.player1 || !mapdata->sprites.exit1
		|| !mapdata->sprites.collectible)
	{
		ft_putendl_fd("Error: can't open xpm file", 2);
		free_sprites(mapdata);
		free_mapdata(mapdata);
		exit(EXIT_FAILURE);
	}
}
