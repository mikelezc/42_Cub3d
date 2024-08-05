/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mouse_hooks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 08:49:39 by mlezcano          #+#    #+#             */
/*   Updated: 2024/08/05 15:33:15 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	bonus_mouse_click(int button, int x, int y, t_game *game)
{
	if (button == 1 && y > 10 && x > 0)
	{
		game->weapon.click = 2;
		bonus_handle_door_interact(game, 0);
	}
	return (0);
}

int	bonus_mouse_move(int x, int y, t_game *game)
{
	int		center_x;
	int		delta_x;
	double	rot_speed;
	double	old_dirx;
	double	old_planex;

	center_x = W_WIDTH / 2;
	delta_x = x - center_x;
	if (delta_x == 0)
		return (0);
	rot_speed = delta_x * MOUSE_SENSITIVITY;
	old_dirx = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * \
	cos(rot_speed) - game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dirx * sin(rot_speed) + \
	game->player.dir_y * cos(rot_speed);
	old_planex = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot_speed) - \
	game->player.plane_y * sin(rot_speed);
	game->player.plane_y = old_planex * sin(rot_speed) + \
	game->player.plane_y * cos(rot_speed);
	if (x != center_x)
		mlx_mouse_move(game->mlx, game->win, center_x, y);
	return (0);
}
