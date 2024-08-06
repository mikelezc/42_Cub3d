/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:29:26 by mlezcano          #+#    #+#             */
/*   Updated: 2024/08/06 06:57:36 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	bonus_draw_ray_on_minimap(t_game *game, t_raycast *vars, \
		int map_width, int map_height)
{
	int		x;
	int		y;
	double	ray_pos_x;
	double	ray_pos_y;
	double	step_size;

	ray_pos_x = game->player.pos_x;
	ray_pos_y = game->player.pos_y;
	step_size = 0.1;
	while (1)
	{
		x = (int)(ray_pos_x * MINIMAP_SCALE);
		y = (int)(ray_pos_y * MINIMAP_SCALE);
		if (x < 0 || x >= map_width * MINIMAP_SCALE || \
		y < 0 || y >= map_height * MINIMAP_SCALE)
			break ;
		if (ft_strchr("NSEW0", \
		game->map.map[(int)ray_pos_y][(int)ray_pos_x]) == NULL)
			break ;
		game->zbuffer[y][x] = RAY_COLOR;
		ray_pos_x += vars->ray_dir_x * step_size;
		ray_pos_y += vars->ray_dir_y * step_size;
	}
}

int	bonus_get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height] != NULL)
		height++;
	return (height);
}

int	bonus_get_map_width(char **map)
{
	int	width;
	int	temp_width;
	int	y;

	width = 0;
	y = 0;
	while (map[y] != NULL)
	{
		temp_width = 0;
		while (map[y][temp_width] != '\0')
			temp_width++;
		if (temp_width > width)
			width = temp_width;
		y++;
	}
	return (width);
}

void	bonus_draw_rays(t_game *game)
{
	int			x;
	int			map_width;
	int			map_height;
	t_raycast	vars;

	map_width = bonus_get_map_width(game->map.map);
	map_height = bonus_get_map_height(game->map.map);
	x = 0;
	while (x < W_WIDTH)
	{
		bonus_ray_trajectory(game, &vars, x);
		bonus_detect_wall(game, &vars);
		bonus_dda(game, &vars);
		bonus_draw_ray_on_minimap(game, &vars, map_width, map_height);
		x++;
	}
}
