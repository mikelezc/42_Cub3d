/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:54:20 by ampjimen          #+#    #+#             */
/*   Updated: 2024/08/04 18:36:27 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cb_check_read_map(char *map_file, t_parse *data, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		cb_error_exit("\033[1;31mError:\nCan not open map file\033[0m");
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (cb_check_valid_line(line, data))
			break ;
		data->reading_pos++;
		free(line);
		line = get_next_line(fd);
	}
	if (line == NULL)
		cb_error_exit("Error:\nMissing Attributes");
	cb_length_map(line, fd, map_file, data);
	if (cb_validate_and_process_map(data, fd, game) == false || data->error)
		cb_error_exit("Error:\nInvalid Map");
	return (close(fd), true);
}

static void	cb_init_player_pos(t_game *game, char **map, int x, int y)
{
	char	pos;

	pos = map[y][x];
	if (pos == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (pos == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (pos == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	else if (pos == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	game->player.plane_x = game->player.dir_y * 0.66;
	game->player.plane_y = -game->player.dir_x * 0.66;
}

void	cb_get_player_pos(char **map, t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\n' && map[y][x] != '\0')
		{
			if (ft_strchr("NESW", map[y][x]) != NULL)
			{
				game->player.pos_x = x + 0.5;
				game->player.pos_y = y + 0.5;
				game->player.dir_x = 0;
				game->player.dir_y = -1;
				cb_init_player_pos(game, map, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}

int	cb_check_duplicate(char *line, t_parse *data)
{
	if (ft_strncmp(line, "NO ", 3) == 0 && ft_strcmp(data->no, "X") != 0)
		return (cb_error_exit("Error:\nDuplicate 'NO' parameter"), true);
	if (ft_strncmp(line, "SO ", 3) == 0 && ft_strcmp(data->so, "X") != 0)
		return (cb_error_exit("Error:\nDuplicate 'SO' parameter"), true);
	if (ft_strncmp(line, "WE ", 3) == 0 && ft_strcmp(data->we, "X") != 0)
		return (cb_error_exit("Error:\nDuplicate 'WE' parameter"), true);
	if (ft_strncmp(line, "EA ", 3) == 0 && ft_strcmp(data->ea, "X") != 0)
		return (cb_error_exit("Error:\nDuplicate 'EA' parameter"), true);
	if (ft_strncmp(line, "F ", 2) == 0 && data->f_color[0] != -1)
		return (cb_error_exit("Error:\nDuplicate 'F' parameter"), true);
	if (ft_strncmp(line, "C ", 2) == 0 && data->c_color[0] != -1)
		return (cb_error_exit("Error:\nDuplicate 'C' parameter"), true);
	return (false);
}

int	cb_check_and_init_map(t_parse *data, int i, t_game *game)
{
	int	pos;
	int	flag;

	pos = 0;
	flag = 0;
	data->raw_map[i] = NULL;
	if (cb_check_duplicate_players(' ', 'Y'))
		return (false);
	cb_get_player_pos(data->raw_map, game);
	while (data->raw_map[pos])
	{
		if (data->raw_map[pos][0] == '\n')
		{
			flag = 1;
		}
		else if (data->raw_map[pos][0] != '\n'
				&& data->raw_map[pos][0] != '\0' && flag)
		{
			cb_error_exit("Error:\nMap contains invalid line");
		}
		pos++;
	}
	game->map.map = data->raw_map;
	return (true);
}
