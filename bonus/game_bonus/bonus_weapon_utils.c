/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_weapon_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:12:32 by mlezcano          #+#    #+#             */
/*   Updated: 2024/07/28 19:22:47 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_img	bonus_load_image(void *mlx, const char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, (char *)path, \
	&img.img_width, &img.img_height);
	if (!img.img)
		bonus_error_exit("Error loading image");
	img.data = (int *)mlx_get_data_addr(img.img, &img.bpp, \
	&img.size_l, &img.endian);
	if (!img.data)
	{
		mlx_destroy_image(mlx, img.img);
		bonus_error_exit("Error getting image data address");
	}
	img.bg_color = img.data[0];
	return (img);
}

void	bonus_load_img_crack(t_game *game)
{
	t_img	img;

	img = bonus_load_image(game->mlx, "./textures/crack.xpm");
	game->crack_img = img;
	game->crack_bg_color = img.bg_color;
}

void	bonus_draw_image(void *mlx, void *win, const t_img *params)
{
	int	i;
	int	j;
	int	color;

	j = 0;
	while (j < params->img_height)
	{
		i = 0;
		while (i < params->img_width)
		{
			color = params->data[j * (params->size_l / 4) + i];
			if (color != params->bg_color)
				mlx_pixel_put(mlx, win, params->x + i, params->y + j, color);
			i++;
		}
		j++;
	}
}

void	bonus_draw_crack_frame(t_game *game)
{
	int	y;
	int	x;

	x = (W_WIDTH - game->crack_img.img_width) / 2;
	y = (W_HEIGHT - game->crack_img.img_height) / 2;
	game->crack_img.x = x;
	game->crack_img.y = y;
	bonus_draw_image(game->mlx, game->win, &game->crack_img);
}
