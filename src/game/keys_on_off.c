/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_on_off.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:05:15 by mlezcano          #+#    #+#             */
/*   Updated: 2024/07/21 07:05:31 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cb_key_off(int key, t_game *game)
{
	if (key == KEY_W)
		game->keys.key_w = 0;
	if (key == KEY_S)
		game->keys.key_s = 0;
	if (key == KEY_D)
		game->keys.key_d = 0;
	if (key == KEY_A)
		game->keys.key_a = 0;
	if (key == KEY_LEFT)
		game->keys.key_left = 0;
	if (key == KEY_RIGHT)
		game->keys.key_right = 0;
	if (key == KEY_SHIFT)
		game->keys.key_shift = 0;
	return (0);
}

int	cb_key_on(int key, t_game *game)
{
	if (key == KEY_ESC)
		cb_exit(game);
	if (key == KEY_W)
		game->keys.key_w = 1;
	if (key == KEY_S)
		game->keys.key_s = 1;
	if (key == KEY_D)
		game->keys.key_d = 1;
	if (key == KEY_A)
		game->keys.key_a = 1;
	if (key == KEY_LEFT)
		game->keys.key_left = 1;
	if (key == KEY_RIGHT)
		game->keys.key_right = 1;
	if (key == KEY_SHIFT)
		game->keys.key_shift = 1;
	return (0);
}
