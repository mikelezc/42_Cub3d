/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map_val_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:54:10 by ampjimen          #+#    #+#             */
/*   Updated: 2024/07/24 20:32:40 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	bonus_is_all_digits(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

static bool	bonus_check_size_map(char **tmp_map)
{
	int	pos;

	pos = 0;
	while (tmp_map[pos])
	{
		if (ft_strlen(tmp_map[pos]) > 40)
			return (false);
		if (pos >= 20)
			return (false);
		pos++;
	}
	return (true);
}

bool	bonus_check_exec(t_parse *data, t_game *game, int i, char **tmp_map)
{
	tmp_map[i] = NULL;
	if (!bonus_check_size_map(tmp_map))
		return (bonus_free_array((void **)tmp_map), false);
	if (!bonus_check_and_init_map(data, i, game))
		return (bonus_free_array((void **)tmp_map), false);
	if (!bonus_check_player_area_enclosed(tmp_map, data->map_length))
		return (bonus_free_array((void **)tmp_map), false);
	if (tmp_map[i - 1][0] == '\0' || tmp_map[i - 1][0] == '\n')
		return (bonus_free_array((void **)tmp_map), false);
	bonus_free_array((void **)tmp_map);
	return (true);
}
