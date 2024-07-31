/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:29:10 by mlezcano          #+#    #+#             */
/*   Updated: 2024/07/29 08:56:22 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cb_image_to_window(t_game *game)
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

void	cb_ceiling_floor(t_game *game)
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

int	cb_game_loop(t_game *game)
{
	cb_ceiling_floor(game);
	cb_raycasting(game);
	cb_image_to_window(game);
	cb_cam_movements(game);
	mlx_do_sync(game->mlx);
	return (0);
}

void	cb_zbuffer_init(t_game *game)
{
	int	i;

	game->zbuffer = (int **)ft_calloc(W_HEIGHT + 1, sizeof(int *));
	if (game->zbuffer == NULL)
		cb_error_exit("Error:\nWhile init zbuffer");
	game->zbuffer[W_HEIGHT] = NULL;
	i = 0;
	while (i < W_HEIGHT)
	{
		game->zbuffer[i] = (int *)ft_calloc(W_WIDTH, sizeof(int));
		if (game->zbuffer[i] == NULL)
			cb_error_exit("Error:\nWhile init zbuffer");
		i++;
	}
}

void	cb_game_main(t_game *game, t_parse *data)
{
	cb_load_game(game, data);
	cb_zbuffer_init(game);
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, \
	"El return de NULL");
	game->img.img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	game->img.data = (int *) mlx_get_data_addr(game->img.img, \
	&game->img.bpp, &game->img.size_l, &game->img.endian);
	mlx_loop_hook(game->mlx, &cb_game_loop, game);
	mlx_hook(game->win, 17, 0, cb_exit, game);
	mlx_hook(game->win, 2, 1L << 0, cb_key_on, game);
	mlx_hook(game->win, 3, 1L << 1, cb_key_off, game);
	mlx_loop(game->mlx);
}
