/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:31:47 by mlezcano          #+#    #+#             */
/*   Updated: 2024/07/29 09:05:25 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	bonus_fill_zbuffer(t_game *game, t_raycast *vars, int x, int y)
{
	int	color;
	int	tex_y;

	tex_y = (int)vars->tex_pos & (TEXHEIGHT - 1);
	vars->tex_pos += vars->step;
	vars->tex_num = 0;
	if (vars->side == 0 && vars->ray_dir_x > 0)
		vars->tex_num = 3;
	else if (vars->side == 0 && vars->ray_dir_x < 0)
		vars->tex_num = 2;
	else if (vars->side == 1 && vars->ray_dir_y > 0)
		vars->tex_num = 1;
	color = game->texture[vars->tex_num][TEXHEIGHT * tex_y + vars->tex_x];
	if (vars->side == 1)
		color = (color >> 1) & 8355711;
	game->zbuffer[y][W_WIDTH - x - 1] = color;
}

void	bonus_dda(t_game *game, t_raycast *vars)
{
	char	map_char;

	while (vars->hit == 0)
	{
		if (vars->side_dist_x < vars->side_dist_y)
		{
			vars->side_dist_x += vars->delta_dist_x;
			vars->map_x += vars->step_x;
			vars->side = 0;
		}
		else
		{
			vars->side_dist_y += vars->delta_dist_y;
			vars->map_y += vars->step_y;
			vars->side = 1;
		}
		map_char = game->map.map[vars->map_y][vars->map_x];
		if (map_char == '1' || map_char == 'D')
			vars->hit = 1;
	}
}

void	bonus_check_ray_collision(t_game *game, t_raycast *vars)
{
	if (vars->ray_dir_x < 0)
	{
		vars->step_x = -1;
		vars->side_dist_x = (game->player.pos_x - vars->map_x)
			* vars->delta_dist_x;
	}
	else
	{
		vars->step_x = 1;
		vars->side_dist_x = (vars->map_x + 1.0 - game->player.pos_x)
			* vars->delta_dist_x;
	}
	if (vars->ray_dir_y < 0)
	{
		vars->step_y = -1;
		vars->side_dist_y = (game->player.pos_y - vars->map_y)
			* vars->delta_dist_y;
	}
	else
	{
		vars->step_y = 1;
		vars->side_dist_y = (vars->map_y + 1.0 - game->player.pos_y)
			* vars->delta_dist_y;
	}
}

void	bonus_ray_trajectory(t_game *game, t_raycast *vars, int x)
{
	vars->camera_x = 2 * x / (double)W_WIDTH - 1;
	vars->ray_dir_x = game->player.dir_x + game->player.plane_x
		* vars->camera_x;
	vars->ray_dir_y = game->player.dir_y + game->player.plane_y
		* vars->camera_x;
	vars->map_x = (int)game->player.pos_x;
	vars->map_y = (int)game->player.pos_y;
	vars->delta_dist_x = fabs(1 / vars->ray_dir_x);
	vars->delta_dist_y = fabs(1 / vars->ray_dir_y);
	vars->hit = 0;
}

void	bonus_raycasting(t_game *game)
{
	int			x;
	t_raycast	vars;

	x = 0;
	while (x < W_WIDTH)
	{
		bonus_ray_trajectory(game, &vars, x);
		bonus_check_ray_collision(game, &vars);
		bonus_dda(game, &vars);
		bonus_render_3d_walls(game, &vars, x);
		x++;
	}
}
