/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:26:45 by falarm            #+#    #+#             */
/*   Updated: 2022/04/20 21:24:16 by falarm           ###   ########.fr       */
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
		ft_error("map");
	i = 0;
	while (mapdata->map[i])
		i++;
	mapdata->width = ft_strlen(mapdata->map[0]);
	mapdata->hight = i;
	mapdata->score = 0;
	mapdata->steps = 0;
	free(line);
	return (mapdata);
}

int	init_player(t_mapdata *mapdata, int i, int j)
{
	mapdata->player_psition_x = i;
	mapdata->player_psition_y = j;
	return (1);
}
