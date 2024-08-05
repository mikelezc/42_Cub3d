/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_raycasting_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:09:53 by mlezcano          #+#    #+#             */
/*   Updated: 2024/08/05 10:20:44 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	bonus_calculate_color(int color, double distance)
{
	double	brightness;
	int		red;
	int		green;
	int		blue;

	brightness = fmax(0.1, 2.0 - 0.1 * (distance * 2.5));
	red = (color >> 16) & 0xFF;
	green = (color >> 8) & 0xFF;
	blue = color & 0xFF;
	red = fmin(255, (int)(red * brightness));
	green = fmin(255, (int)(green * brightness));
	blue = fmin(255, (int)(blue * brightness));
	return ((red << 16) | (green << 8) | blue);
}

void	bonus_apply_door_texture(t_game *game, t_raycast *vars, int x, int y)
{
	int	color;
	int	tex_y;

	tex_y = (int)vars->tex_pos & (TEXHEIGHT - 1);
	vars->tex_pos += vars->step;
	color = game->texture[DOOR_TEXTURE][TEXHEIGHT * tex_y + vars->tex_x];
	game->zbuffer[y][W_WIDTH - x - 1] = color;
}

void	calculate_wall_and_texture_params(t_game *game, t_raycast *vars)
{
	if (vars->side == 0)
		vars->wall_x = game->player.pos_y + \
		vars->perp_wall_dist * vars->ray_dir_y;
	else
		vars->wall_x = game->player.pos_x + \
		vars->perp_wall_dist * vars->ray_dir_x;
	vars->wall_x -= floor(vars->wall_x);
	vars->tex_x = (int)(vars->wall_x * (double)TEXWIDTH);
	if (vars->side == 0 && vars->ray_dir_x > 0)
		vars->tex_x = TEXWIDTH - vars->tex_x - 1;
	if (vars->side == 1 && vars->ray_dir_y < 0)
		vars->tex_x = TEXWIDTH - vars->tex_x - 1;
	vars->step = 1.0 * TEXHEIGHT / vars->line_height;
	vars->tex_pos = (vars->draw_start - \
	W_HEIGHT / 2 + vars->line_height / 2) * vars->step;
}

void	calculate_basic_raycast_params(t_game *game, t_raycast *vars)
{
	if (vars->side == 0)
		vars->perp_wall_dist = (vars->map_x - game->player.pos_x + \
		(1 - vars->step_x) / 2) / vars->ray_dir_x;
	else
		vars->perp_wall_dist = (vars->map_y - game->player.pos_y + \
		(1 - vars->step_y) / 2) / vars->ray_dir_y;
	vars->line_height = (int)(W_HEIGHT / vars->perp_wall_dist);
	vars->draw_start = -vars->line_height / 2 + W_HEIGHT / 2;
	if (vars->draw_start < 0)
		vars->draw_start = 0;
	vars->draw_end = vars->line_height / 2 + W_HEIGHT / 2;
	if (vars->draw_end >= W_HEIGHT)
		vars->draw_end = W_HEIGHT - 1;
}

void	bonus_render_3d_walls(t_game *game, t_raycast *vars, int x)
{
	char	map_char;
	int		y;

	calculate_basic_raycast_params(game, vars);
	calculate_wall_and_texture_params(game, vars);
	map_char = game->map.map[vars->map_y][vars->map_x];
	if (map_char == 'd')
		return ;
	if (map_char == 'D')
	{
		y = vars->draw_start;
		while (y < vars->draw_end)
		{
			bonus_apply_door_texture(game, vars, x, y);
			y++;
		}
		return ;
	}
	y = vars->draw_start;
	while (y < vars->draw_end)
	{
		bonus_fill_zbuffer(game, vars, x, y);
		y++;
	}
}
