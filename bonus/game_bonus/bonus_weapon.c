/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_weapon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:51:15 by mlezcano          #+#    #+#             */
/*   Updated: 2024/08/05 15:43:20 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	bonus_snprintf(char *buffer, size_t size, char *format, int index)
{
	char	*prefix;
	char	*suffix;
	size_t	prefix_len;
	size_t	suffix_len;

	if (ft_strcmp(format, "./textures/hand/handsprite%d.xpm") == 0)
	{
		prefix = "./textures/hand/handsprite";
		suffix = ".xpm";
		prefix_len = ft_strlen(prefix);
		suffix_len = ft_strlen(suffix);
		if (size >= prefix_len + suffix_len + 2)
		{
			ft_strlcpy(buffer, prefix, size);
			buffer[prefix_len] = '0' + index;
			buffer[prefix_len + 1] = '\0';
			ft_strlcpy(buffer + prefix_len + 1, suffix, size - prefix_len - 1);
		}
	}
}

void	bonus_render_weapon(t_weapon *weapon, t_game *game)
{
	if (weapon->click != 2)
	{
		weapon->weapon_img.x = weapon->weapon_x;
		weapon->weapon_img.y = weapon->weapon_y;
		bonus_draw_image(game->mlx, game->win, &weapon->weapon_img);
	}
	else if (weapon->click == 2)
	{
		bonus_draw_crack_frame(game);
		weapon->weapon_imgs[weapon->current_sprite].x = weapon->weapon_x;
		weapon->weapon_imgs[weapon->current_sprite].y = weapon->weapon_y;
		bonus_draw_image(game->mlx, game->win, \
		&weapon->weapon_imgs[weapon->current_sprite]);
		weapon->frame_count++;
		if (weapon->frame_count >= 20)
		{
			weapon->current_sprite++;
			weapon->frame_count = 0;
			if (weapon->current_sprite >= 4)
			{
				weapon->current_sprite = 0;
				weapon->click = 0;
			}
		}
	}
}

void	bonus_load_weapon_animation(t_game *game)
{
	char	sprite_path[50];
	int		i;

	i = -1;
	while (++i < 4)
	{
		bonus_snprintf(sprite_path, sizeof(sprite_path), \
		"./textures/hand/handsprite%d.xpm", i + 1);
		game->weapon.weapon_imgs[i] = bonus_load_image(game->mlx, sprite_path);
	}
	game->weapon.current_sprite = 0;
	game->weapon.frame_count = 0;
}

void	bonus_load_main_weapon(t_game *game)
{
	game->weapon.weapon_img = bonus_load_image(game->mlx, \
	"./textures/hand/handsprite.xpm");
	game->weapon.weapon_x = (W_WIDTH - game->weapon.weapon_img.img_width) / 2;
	game->weapon.weapon_y = W_HEIGHT - game->weapon.weapon_img.img_height + 10;
}

void	bonus_load_img_weapon(t_game *game)
{
	bonus_load_main_weapon(game);
	bonus_load_weapon_animation(game);
	game->weapon.click = 0;
}
