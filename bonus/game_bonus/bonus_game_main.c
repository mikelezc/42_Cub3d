/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_game_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:29:10 by mlezcano          #+#    #+#             */
/*   Updated: 2024/08/05 15:41:58 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	bonus_image_to_window(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			game->img.data[(y * W_WIDTH) + x] = game->zbuffer[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	bonus_ceiling_floor(t_game *game)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			color = game->map.floor_color;
			game->zbuffer[y][x] = color;
			color = game->map.ceil_color;
			game->zbuffer[W_HEIGHT - y - 1][x] = color;
			x++;
		}
		y++;
	}
}

int	bonus_game_loop(t_game *game)
{
	bonus_ceiling_floor(game);
	bonus_raycasting(game);
	bonus_minimap(game);
	bonus_door_input(game);
	bonus_image_to_window(game);
	bonus_cam_movements(game);
	bonus_render_weapon(&game->weapon, game);
	bonus_helper(game);
	mlx_do_sync(game->mlx);
	return (0);
}

void	bonus_zbuffer_init(t_game *game)
{
	int	i;

	game->zbuffer = (int **)ft_calloc(W_HEIGHT + 1, sizeof(int *));
	if (game->zbuffer == NULL)
		bonus_error_exit("Error:\nWhile init zbuffer");
	game->zbuffer[W_HEIGHT] = NULL;
	i = 0;
	while (i < W_HEIGHT)
	{
		game->zbuffer[i] = (int *)ft_calloc(W_WIDTH, sizeof(int));
		if (game->zbuffer[i] == NULL)
			bonus_error_exit("Error:\nWhile init zbuffer");
		i++;
	}
}

void	bonus_game_main(t_game *game, t_parse *data)
{
	bonus_load_game(game, data);
	bonus_zbuffer_init(game);
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, \
	"El return de NULL");
	game->img.img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	game->img.data = (int *) mlx_get_data_addr(game->img.img, \
	&game->img.bpp, &game->img.size_l, &game->img.endian);
	mlx_loop_hook(game->mlx, &bonus_game_loop, game);
	mlx_hook(game->win, 17, 0, bonus_exit, game);
	mlx_hook(game->win, 2, 1L << 0, bonus_key_on, game);
	mlx_hook(game->win, 3, 1L << 1, bonus_key_off, game);
	mlx_hook(game->win, 6, 1L << 6, bonus_mouse_move, game);
	mlx_mouse_hook(game->win, bonus_mouse_click, game);
	mlx_mouse_move(game->mlx, game->win, W_WIDTH / 2, W_HEIGHT / 2);
	mlx_mouse_hide(game->mlx, game->win);
	mlx_loop(game->mlx);
}
