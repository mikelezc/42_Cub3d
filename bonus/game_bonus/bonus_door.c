/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:10:32 by ampjimen          #+#    #+#             */
/*   Updated: 2024/07/28 16:32:31 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	bonus_handle_door_interact(t_game *game, int set_key_space)
{
	int	player_map_x;
	int	player_map_y;

	player_map_x = (int)(game->player.pos_x + 0.5);
	player_map_y = (int)(game->player.pos_y + 0.5);
	bonus_toggle_door(game, player_map_x, player_map_y);
	if (set_key_space)
		game->keys.key_space = 1;
}

int	bonus_calc_direction(float dir)
{
	if (dir >= 0)
		return ((int)(dir + 0.5));
	else
		return ((int)(dir - 0.5));
}

void	bonus_toggle_door_if_nearby(t_game *game, int check_x, int check_y)
{
	if ((int)game->player.pos_x == check_x \
	&& (int)game->player.pos_y == check_y)
		return ;
	if (game->map.map[check_y][check_x] == 'D')
		game->map.map[check_y][check_x] = 'd';
	else if (game->map.map[check_y][check_x] == 'd')
		game->map.map[check_y][check_x] = 'D';
}

void	bonus_toggle_door(t_game *game, int p_map_x, int p_map_y)
{
	int	dir_x;
	int	dir_y;

	dir_x = bonus_calc_direction(game->player.dir_x);
	dir_y = bonus_calc_direction(game->player.dir_y);
	bonus_toggle_door_if_nearby(game, p_map_x + dir_x - 1, p_map_y + dir_y - 1);
	bonus_toggle_door_if_nearby(game, p_map_x + dir_x - 1, p_map_y + dir_y);
	bonus_toggle_door_if_nearby(game, p_map_x + dir_x - 1, p_map_y + dir_y + 1);
	bonus_toggle_door_if_nearby(game, p_map_x + dir_x, p_map_y + dir_y - 1);
	bonus_toggle_door_if_nearby(game, p_map_x + dir_x, p_map_y + dir_y);
	bonus_toggle_door_if_nearby(game, p_map_x + dir_x, p_map_y + dir_y + 1);
	bonus_toggle_door_if_nearby(game, p_map_x + dir_x + 1, p_map_y + dir_y - 1);
	bonus_toggle_door_if_nearby(game, p_map_x + dir_x + 1, p_map_y + dir_y);
	bonus_toggle_door_if_nearby(game, p_map_x + dir_x + 1, p_map_y + dir_y + 1);
}
