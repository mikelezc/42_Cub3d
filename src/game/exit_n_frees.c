/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_n_frees.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:01:18 by mlezcano          #+#    #+#             */
/*   Updated: 2024/08/05 15:50:26 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cb_free_array(void **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = -1;
	while (arr[++i] != NULL)
		free(arr[i]);
	free(arr);
}

void	cb_free_textures(int **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = -1;
	while (arr[++i] != NULL)
		free(arr[i]);
}

int	cb_exit(t_game *game)
{
	if (game->map.map)
		cb_free_array((void **)game->map.map);
	if (game->zbuffer)
		cb_free_array((void **)game->zbuffer);
	if (game->texture)
		cb_free_array((void **)game->texture);
	mlx_destroy_image(game->mlx, game->img.img);
	exit (0);
}

void	cb_error_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
