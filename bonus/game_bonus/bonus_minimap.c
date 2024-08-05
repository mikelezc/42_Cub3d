/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:00:20 by mlezcano          #+#    #+#             */
/*   Updated: 2024/08/05 15:32:58 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	bonus_put_miniplayer(t_game *game)
{
	int	x;
	int	y;
	int	dx;
	int	dy;

	x = (int)(game->player.pos_x * MINIMAP_SCALE);
	y = (int)(game->player.pos_y * MINIMAP_SCALE);
	x -= PLAYER_SIZE / 2;
	y -= PLAYER_SIZE / 2;
	dy = 0;
	while (dy < PLAYER_SIZE)
	{
		dx = 0;
		while (dx < PLAYER_SIZE)
		{
			game->zbuffer[y + dy][x + dx] = PLAYER_COLOR;
			dx++;
		}
		dy++;
	}
}

void	bonus_fill_minimap(t_game *game, int color, int x, int y)
{
	int	dx;
	int	dy;

	dy = 0;
	while (dy < MINIMAP_SCALE)
	{
		dx = 0;
		while (dx < MINIMAP_SCALE)
		{
			game->zbuffer[(y * MINIMAP_SCALE) + dy] \
			[(x * MINIMAP_SCALE) + dx] = color;
			dx++;
		}
		dy++;
	}
}

void	bonus_put_minimap(t_game *game)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	while (game->map.map[y] != NULL)
	{
		x = 0;
		while (game->map.map[y][x] != '\0')
		{
			color = SPACE_COLOR;
			if (game->map.map[y][x] == 'D')
				color = DOOR_COLOR_C;
			else if (game->map.map[y][x] == 'd')
				color = DOOR_COLOR_O;
			else if (ft_strchr("NESW0", game->map.map[y][x]))
				color = WALL_COLOR;
			bonus_fill_minimap(game, color, x, y);
			x++;
		}
		y++;
	}
}

void	bonus_minimap(t_game *game)
{
	if (game->keys.key_m)
	{
		game->map.minimap_on = !game->map.minimap_on;
		game->keys.key_m = 0;
	}
	if (game->map.minimap_on)
	{
		bonus_put_minimap(game);
		bonus_draw_rays(game);
		bonus_put_miniplayer(game);
	}
}
