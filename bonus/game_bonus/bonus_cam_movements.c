/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_cam_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:10:11 by mlezcano          #+#    #+#             */
/*   Updated: 2024/08/05 14:55:55 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	bonus_move_speed(t_game *game)
{
	double	speed;

	if (game->keys.key_shift)
		speed = MOVE_SPEED * 3;
	else
		speed = MOVE_SPEED;
	return (speed);
}

void	bonus_rotate_cam(t_game *game, t_player *p)
{
	double	old_dirx;
	double	old_planex;
	double	rot_speed;

	rot_speed = 0;
	if (game->keys.key_right)
		rot_speed = ROT_SPEED;
	if (game->keys.key_left)
		rot_speed = -ROT_SPEED;
	if (rot_speed != 0)
	{
		old_dirx = p->dir_x;
		p->dir_x = p->dir_x * cos(rot_speed) - p->dir_y * sin(rot_speed);
		p->dir_y = old_dirx * sin(rot_speed) + p->dir_y * cos(rot_speed);
		old_planex = p->plane_x;
		p->plane_x = p->plane_x * cos(rot_speed) - p->plane_y * sin(rot_speed);
		p->plane_y = old_planex * sin(rot_speed) + p->plane_y * cos(rot_speed);
	}
}

void	bonus_side_mov_cam(t_game *game, t_player *p)
{
	char	**map;
	double	speed;

	speed = bonus_move_speed(game);
	map = game->map.map;
	if (game->keys.key_d)
	{
		if (ft_strchr("NESW0d", map[(int)(p->pos_y + p->dir_x \
		* (speed + SIDE_MARGIN))][(int)(p->pos_x)]) != NULL)
			p->pos_y += p->dir_x * speed;
		if (ft_strchr("NESW0d", map[(int)(p->pos_y)][(int)(p->pos_x - p->dir_y \
		* (speed + SIDE_MARGIN))]) != NULL)
			p->pos_x -= p->dir_y * speed;
	}
	if (game->keys.key_a)
	{
		if (ft_strchr("NESW0d", map[(int)(p->pos_y - p->dir_x \
		* (speed + SIDE_MARGIN))][(int)(p->pos_x)]) != NULL)
			p->pos_y -= p->dir_x * speed;
		if (ft_strchr("NESW0d", map[(int)(p->pos_y)][(int)(p->pos_x + p->dir_y \
		* (speed + SIDE_MARGIN))]) != NULL)
			p->pos_x += p->dir_y * speed;
	}
}

void	bonus_frwr_back_cam(t_game *game, t_player *p)
{
	char	**map;
	double	speed;

	speed = bonus_move_speed(game);
	map = game->map.map;
	if (game->keys.key_w)
	{
		if (ft_strchr("NESW0d", map[(int)(p->pos_y + p->dir_y \
		* (speed + FRNT_MARGIN))][(int)(p->pos_x)]) != NULL)
			p->pos_y += p->dir_y * speed;
		if (ft_strchr("NESW0d", map[(int)(p->pos_y)][(int)(p->pos_x + p->dir_x \
		* (speed + FRNT_MARGIN))]) != NULL)
			p->pos_x += p->dir_x * speed;
	}
	if (game->keys.key_s)
	{
		if (ft_strchr("NESW0d", map[(int)(p->pos_y - p->dir_y \
		* (speed + BACK_MARGIN))][(int)(p->pos_x)]) != NULL)
			p->pos_y -= p->dir_y * speed;
		if (ft_strchr("NESW0d", map[(int)(p->pos_y)][(int)(p->pos_x - p->dir_x \
		* (speed + BACK_MARGIN))]) != NULL)
			p->pos_x -= p->dir_x * speed;
	}
}

void	bonus_cam_movements(t_game *game)
{
	t_player	*plyr;

	plyr = &game->player;
	bonus_frwr_back_cam(game, plyr);
	bonus_side_mov_cam(game, plyr);
	bonus_rotate_cam(game, plyr);
}
