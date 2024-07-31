/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_door_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:21:12 by ampjimen          #+#    #+#             */
/*   Updated: 2024/07/29 07:36:44 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	bonus_calculate_door_position(t_game *game, t_door_params *params)
{
	if (game->player.dir_x >= 0)
		params->dir_x = 1;
	else
		params->dir_x = -1;
	if (game->player.dir_y >= 0)
		params->dir_y = 1;
	else
		params->dir_y = -1;
	params->door_x = params->player_map_x + params->dir_x;
	params->door_y = params->player_map_y + params->dir_y;
}

void	bonus_toggle_door_state(t_game *game, t_door_params *params)
{
	char	map_char;

	map_char = game->map.map[params->door_y][params->door_x];
	if (map_char == 'D')
		game->map.map[params->door_y][params->door_x] = 'd';
	else if (map_char == 'd')
		game->map.map[params->door_y][params->door_x] = 'D';
}

void	bonus_door_input(t_game *game)
{
	t_door_params	params;

	if (game->keys.key_space)
	{
		game->click = 2;
		params.player_map_x = (int)game->player.pos_x;
		params.player_map_y = (int)game->player.pos_y;
		bonus_calculate_door_position(game, &params);
		bonus_toggle_door_state(game, &params);
	}
}
