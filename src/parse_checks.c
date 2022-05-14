/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:19:58 by falarm            #+#    #+#             */
/*   Updated: 2022/04/21 18:36:47 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_args(int ac, char **av)
{
	if (ac != 2)
		error_arg("wrong number of arguments.");
	if (ft_strrchr(av[1], '/') && ft_strlen(ft_strrchr(av[1], '/')) == 5)
		error_arg("It is not a map.");
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		error_arg("use files with 'ber' extension.");
	if (open(av[1], O_DIRECTORY) != -1)
		error_fd();
}

void	check_map_whole(t_mapdata *mapdata, char **av)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_fd();
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		i++;
		if (!line)
			break ;
		free(line);
	}
	if (i != mapdata->hight + 1)
		ft_error("file has empty line", mapdata);
	close(fd);
}

void	check_map_line(t_mapdata *mapdata)
{
	int		i;
	int		j;
	char	*str;

	str = "01CEP";
	i = -1;
	while (mapdata->map[++i])
	{
		j = 0;
		while (mapdata->map[i][j])
		{
			if (!ft_strchr(str, mapdata->map[i][j]))
				ft_error("tne map has wrong simbol", mapdata);
			j++;
		}
		if (mapdata->width != j)
			ft_error("the map is wrong form", mapdata);
	}
}

void	check_map_arg(t_mapdata *mapdata, int i, int j)
{
	int	player;
	int	exit;

	player = 0;
	exit = 0;
	while (mapdata->map[++i])
	{
		j = 0;
		while (mapdata->map[i][++j])
		{
			if (mapdata->map[i][j] == 'P')
				player += init_player(mapdata, i, j);
			else if (mapdata->map[i][j] == 'C')
				mapdata->score++;
		}
	}
	if (player != 1)
		ft_error("more then one player", mapdata);
	if (mapdata->score < 0)
		ft_error("don't have collectible", mapdata);
	if (exit < 0)
		ft_error("more then one exit", mapdata);
}

void	check_map_border(t_mapdata *mapdata, int i, int j)
{
	while (mapdata->map[0][++i])
	{
		if (mapdata->map[0][i] != '1')
			ft_error("the map is open at the top", mapdata);
	}
	i = 0;
	while (mapdata->map[mapdata->hight -1][++i])
	{
		if (mapdata->map[mapdata->hight -1][i] != '1')
			ft_error("the map is open from the bottom", mapdata);
	}
	i = 0;
	while (mapdata->map[++i] && i < mapdata->width - 1)
	{
		j = -1;
		while (mapdata->map[i][++j])
		{
			if (mapdata->map[i][0] != '1')
				ft_error("the card is open on the left", mapdata);
			else if (mapdata->map[i][mapdata->width - 1] != '1')
				ft_error("the card is open on the right", mapdata);
		}
	}
}
