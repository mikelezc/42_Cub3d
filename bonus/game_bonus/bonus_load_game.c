/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_load_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:24:43 by mlezcano          #+#    #+#             */
/*   Updated: 2024/08/04 17:42:38 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	bonus_get_int_color_fl_cel(t_game *game, t_parse *data)
{
	game->map.ceil_color = ((data->c_color[0] & 0xFF) << 16) | \
	((data->c_color[1] & 0xFF) << 8) | \
	(data->c_color[2] & 0xFF);
	game->map.floor_color = ((data->f_color[0] & 0xFF) << 16) | \
	((data->f_color[1] & 0xFF) << 8) | \
	(data->f_color[2] & 0xFF);
}

void	bonus_load_texture(t_game *game, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	y = 0;
	img->img = mlx_xpm_file_to_image(game->mlx, path, \
	&img->img_width, &img->img_height);
	if (!img->img)
		bonus_error_exit("Error loading texture");
	img->data = (int *)mlx_get_data_addr(img->img, \
	&img->bpp, &img->size_l, &img->endian);
	if (!img->data || img->img_width != TEXWIDTH \
	|| img->img_height != TEXHEIGHT)
		bonus_error_exit("Error texture size or format");
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, img->img);
}

void	bonus_load_img_wall(t_game *game, t_parse *data)
{
	t_img	img;

	bonus_load_texture(game, game->texture[0], data->so, &img);
	bonus_load_texture(game, game->texture[1], data->no, &img);
	bonus_load_texture(game, game->texture[2], data->we, &img);
	bonus_load_texture(game, game->texture[3], data->ea, &img);
	bonus_load_texture(game, game->texture[DOOR_TEXTURE], \
	"./textures/trial_images/door_texture.xpm", &img);
	free(data->no);
	free(data->so);
	free(data->ea);
	free(data->we);
}

void	bonus_set_img_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->texture = ft_calloc(6, sizeof(int *));
	if (!game->texture)
		bonus_error_exit("Error inicializating textures");
	while (i < 5)
	{
		game->texture[i] = ft_calloc(TEXHEIGHT * TEXWIDTH + 1, sizeof(int));
		if (!game->texture[i++])
			bonus_error_exit("Error inicializating textures");
	}
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < TEXHEIGHT * TEXWIDTH)
		{
			game->texture[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	bonus_load_game(t_game *game, t_parse *data)
{
	bonus_set_img_wall(game);
	bonus_load_img_wall(game, data);
	bonus_get_int_color_fl_cel(game, data);
	bonus_load_img_crack(game);
	bonus_load_img_weapon(game);
	bonus_load_img_helper(game);
}
