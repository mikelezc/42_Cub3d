/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:05:03 by mlezcano          #+#    #+#             */
/*   Updated: 2024/07/31 17:16:25 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cb_init_vars(t_game *game)
{
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.66;
	game->keys.key_w = 0;
	game->keys.key_a = 0;
	game->keys.key_s = 0;
	game->keys.key_d = 0;
	game->keys.key_left = 0;
	game->keys.key_right = 0;
	game->keys.key_shift = 0;
	game->map.map = NULL;
	game->zbuffer = NULL;
	game->texture = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_parse	data;

	if (argc == 2)
	{
		game.mlx = mlx_init();
		cb_init_vars(&game);
		data = cb_parse_file(argv[1], &game);
		cb_game_main(&game, &data);
	}
	else
	{
		printf("Error:\nWrong number of arguments\n");
		cb_input_help();
	}
}
