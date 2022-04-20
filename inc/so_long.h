/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:38:36 by falarm            #+#    #+#             */
/*   Updated: 2022/04/20 21:36:50 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft_src/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>

typedef struct s_mapdata
{
	int		hight;
	int		width;
	int		player_psition_x;
	int		player_psition_y;
	int		score;
	int		curent_score;
	int		steps;
	int		game_over;
	char	**map;
	void	*wall;
	void	*exit;
	void	*item;
	void	*player;
	void	*floor;
	void	*enemy;
	int		*enemy_position;
}	t_mapdata;

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
}	t_ptr;

void		ft_error(char *str);
void		error_arg(char *str);
void		error_fd(void);
void		check_args(int ac, char **av);
void		check_map_whole(t_mapdata *mapdata, char **av);
void		check_map_line(t_mapdata *mapdata);
void		check_map_arg(t_mapdata *mapdata, int i, int j);
void		check_map_border(t_mapdata *mapdata, int i, int j);
char		*get_map_in_line(char **av);
int			init_player(t_mapdata *mapdata, int i, int j);
t_mapdata	*init_mapdata(char *line);

#endif
