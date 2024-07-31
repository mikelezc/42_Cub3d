/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:40:58 by mlezcano          #+#    #+#             */
/*   Updated: 2024/07/30 14:57:56 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	bonus_load_img_helper(t_game *game)
{
	game->help = bonus_load_image(game->mlx, \
	"./textures/trial_images/help2.xpm");
}

void	bonus_helper(t_game *game)
{
	int	y;
	int	x;

	x = (W_WIDTH - game->help.img_width) / 2;
	y = (W_HEIGHT - game->help.img_height) / 2;
	game->help.x = x;
	game->help.y = y;
	if (game->keys.key_h)
	{
		game->help_on = !game->help_on;
		game->keys.key_h = 0;
	}
	if (game->help_on)
		bonus_draw_image(game->mlx, game->win, &game->help);
}
