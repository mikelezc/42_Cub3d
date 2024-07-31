/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:36:54 by mlezcano          #+#    #+#             */
/*   Updated: 2024/07/29 13:49:53 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cb_render_3d_walls(t_game *game, t_raycast *vars)
{
	vars->perp_wall_dist = (vars->map_y - game->player.pos_y
			+ (1 - vars->step_y) / 2) / vars->ray_dir_y;
	if (vars->side == 0)
		vars->perp_wall_dist = (vars->map_x - game->player.pos_x
				+ (1 - vars->step_x) / 2) / vars->ray_dir_x;
	vars->line_height = (int)(W_HEIGHT / vars->perp_wall_dist);
	vars->draw_start = -vars->line_height / 2 + W_HEIGHT / 2;
	if (vars->draw_start < 0)
		vars->draw_start = 0;
	vars->draw_end = vars->line_height / 2 + W_HEIGHT / 2;
	if (vars->draw_end >= W_HEIGHT)
		vars->draw_end = W_HEIGHT - 1;
	vars->wall_x = game->player.pos_x + vars->perp_wall_dist * vars->ray_dir_x;
	if (vars->side == 0)
		vars->wall_x = game->player.pos_y + vars->perp_wall_dist
			* vars->ray_dir_y;
	vars->wall_x -= floor(vars->wall_x);
	vars->tex_x = (int)(vars->wall_x * (double)TEXWIDTH);
	if (vars->side == 0 && vars->ray_dir_x > 0)
		vars->tex_x = TEXWIDTH - vars->tex_x - 1;
	if (vars->side == 1 && vars->ray_dir_y < 0)
		vars->tex_x = TEXWIDTH - vars->tex_x - 1;
	vars->step = 1.0 * TEXHEIGHT / vars->line_height;
	vars->tex_pos = (vars->draw_start - W_HEIGHT / 2
			+ vars->line_height / 2) * vars->step;
}
