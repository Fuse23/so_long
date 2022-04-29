/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:38:36 by falarm            #+#    #+#             */
/*   Updated: 2022/04/29 19:30:05 by falarm           ###   ########.fr       */
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

// sprites
# define WALL			"sprites/tiles/wall_1.xpm"
# define FLOOR			"sprites/tiles/floor_1.xpm"
# define PLAYER1		"sprites/heroes/knight_idle_anim_f0.xpm"
# define PLAYER2		"sprites/heroes/knight_run_anim_f5.xpm"
# define EXIT0			"sprites/tiles/door_anim_opening_f3.xpm"
# define EXIT1			"sprites/tiles/door_closed.xpm"
# define COLLECTIBLE	"sprites/collectible/key_silver.xpm"
# define ENEMY1			"sprites/enemies/fly_anim_f1.xpm"
# define ENEMY2			"sprites/enemies/fly_anim_f3.xpm"

// keys
# define ESC	53
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2

// size sprite X Y
# define SPRITE_X	16
# define SPRITE_Y	16

typedef struct s_sprites
{
	void	*wall;
	void	*floor;
	void	*player1;
	void	*player2;
	void	*exit0;
	void	*exit1;
	void	*collectible;
	void	*enemy1;
	void	*enemy2;
}	t_sprites;

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
}	t_ptr;

typedef struct s_mapdata
{
	int			hight;
	int			width;
	int			player_psition_x;
	int			player_psition_y;
	int			score;
	int			curent_score;
	int			steps;
	int			game_over;
	char		**map;
	int			*enemy_position;
	t_sprites	sprites;
	t_ptr		ptr;
}	t_mapdata;

void		free_mapdata(t_mapdata *mapdata);
void		ft_error(char *str, t_mapdata *mapdata);
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
void		init_sprites(t_mapdata *mapdata);
int			keys(int key, t_mapdata *mapdata);
int			draw(t_mapdata *mapdata);
int			end(t_mapdata *mapdata);
void		steps(t_mapdata *mapdata);
void		move_right(t_mapdata *mapdata);
void		move_left(t_mapdata *mapdata);
void		move_up(t_mapdata *mapdata);
void		move_down(t_mapdata *mapdata);
//bonus
void		check_map_line_bonus(t_mapdata *mapdata);
void		init_sprites2(t_mapdata *mapdata, int x, int y);

#endif
