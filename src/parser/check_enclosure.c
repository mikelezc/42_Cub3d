/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enclosure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:52:55 by ampjimen          #+#    #+#             */
/*   Updated: 2024/07/08 19:12:44 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	cb_is_in_map(int x, int y, char **map, int size)
{
	if (y < 0 || y >= size)
		return (false);
	return (x >= 0 && x <= (int)ft_strlen(map[y]) - 1);
}

static bool	cb_check_area_closed(int x, int y, char **map, int size)
{
	bool	is_closed;

	if (!cb_is_in_map(x, y, map, size))
		return (false);
	if (map[y][x] == '1' || map[y][x] == ' ')
		return (true);
	map[y][x] = '1';
	is_closed = true;
	is_closed &= cb_check_area_closed(x, y - 1, map, size);
	is_closed &= cb_check_area_closed(x, y + 1, map, size);
	is_closed &= cb_check_area_closed(x - 1, y, map, size);
	is_closed &= cb_check_area_closed(x + 1, y, map, size);
	return (is_closed);
}

bool	cb_check_player_area_enclosed(char **map, int size)
{
	int	player[2];
	int	x_y[2];

	player[0] = -1;
	player[1] = -1;
	x_y[0] = 0;
	x_y[1] = 0;
	while (x_y[0] < size && player[0] == -1)
	{
		x_y[1] = 0;
		while (x_y[1] < (int)ft_strlen(map[x_y[0]]) && player[0] == -1)
		{
			if (map[x_y[0]][x_y[1]] == 'S' || map[x_y[0]][x_y[1]] == 'N' ||
				map[x_y[0]][x_y[1]] == 'E' || map[x_y[0]][x_y[1]] == 'W')
			{
				player[0] = x_y[1];
				player[1] = x_y[0];
			}
			x_y[1]++;
		}
		x_y[0]++;
	}
	if (player[0] == -1)
		return (false);
	return (cb_check_area_closed(player[0], player[1], map, size));
}
