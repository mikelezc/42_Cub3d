/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_exit_n_frees.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:01:18 by mlezcano          #+#    #+#             */
/*   Updated: 2024/07/22 19:50:05 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	bonus_free_array(void **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = -1;
	while (arr[++i] != NULL)
		free(arr[i]);
	free(arr);
}

void	bonus_free_textures(int **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = -1;
	while (arr[++i] != NULL)
		free(arr[i]);
}

void	bonus_free_weapon_imgs(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
		mlx_destroy_image(game->mlx, game->weapon_imgs[i].img);
}

int	bonus_exit(t_game *game)
{
	if (game->weapon_imgs)
		bonus_free_weapon_imgs(game);
	if (game->map.map)
		bonus_free_array((void **)game->map.map);
	if (game->zbuffer)
		bonus_free_array((void **)game->zbuffer);
	if (game->texture)
		bonus_free_array((void **)game->texture);
	mlx_destroy_image(game->mlx, game->img.img);
	exit (0);
}

void	bonus_error_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
