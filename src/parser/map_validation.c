/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:54:58 by ampjimen          #+#    #+#             */
/*   Updated: 2024/08/04 18:44:50 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cb_validate_and_process_map(t_parse *data, int fd, t_game *game)
{
	int			i;
	static int	k;
	char		*line;
	char		**tmp_map;

	line = get_next_line(fd);
	while (k++ != data->reading_pos)
		line = get_line(fd, line);
	while (line != NULL && cb_check_only_spaces(line))
		line = get_line(fd, line);
	data->raw_map = ft_calloc((data->map_length + 1), sizeof(char *));
	tmp_map = ft_calloc((data->map_length + 1), sizeof(char *));
	if (data->raw_map == NULL || tmp_map == NULL)
		cb_error_exit("Error:\nMalloc failed");
	i = 0;
	while (line != NULL)
	{
		if (cb_not_valid_map_char(line))
			return (cb_free_array((void **)tmp_map), free(line), false);
		tmp_map[i] = ft_strdup(line);
		data->raw_map[i++] = cb_adjust_map_line(line, data);
		line = get_line(fd, line);
	}
	free(line);
	return (close(fd), cb_check_exec(data, game, i, tmp_map));
}

void	cb_length_map(char *line, int fd, char *map_file, t_parse *data)
{
	size_t	line_length;

	while (line != NULL && cb_check_only_spaces(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		line_length = ft_strlen(line);
		if (line_length > data->line_size)
			data->line_size = line_length;
		data->map_length++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	fd = open(map_file, O_RDONLY);
}

int	cb_check_only_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (!ft_isspace(line[i]))
			return (false);
		i++;
	}
	return (true);
}

int	cb_not_valid_map_char(char *line)
{
	int		i;
	char	c;

	i = 0;
	if (line[i] == '\n' || line[i] == '\0')
		return (true);
	while (line[i] != '\n' && line[i] != '\0')
	{
		c = line[i];
		if (c == ' ' || c == '0' || c == '1'
			|| c == 'N' || c == 'S' || c == 'W'
			|| c == 'E')
		{
			if (cb_check_duplicate_players(c, 'N'))
				return (true);
			i++;
		}
		else if (c == '\0')
			return (false);
		else
			cb_error_exit("Error:\nInvalid caracter");
	}
	return (false);
}

int	cb_check_duplicate_players(char c, char option)
{
	static int	n = 0;
	static int	s = 0;
	static int	w = 0;
	static int	e = 0;
	int			total_players;

	if (c == 'N')
		n++;
	else if (c == 'S')
		s++;
	else if (c == 'W')
		w++;
	else if (c == 'E')
		e++;
	if (n > 1 || s > 1 || w > 1 || e > 1)
		cb_error_exit("Error:\nDuplicate Player");
	if (option == 'Y')
	{
		total_players = n + s + w + e;
		if (total_players == 0)
			cb_error_exit("Error:\nMissing Player");
		else if (total_players > 1)
			cb_error_exit("Error:\nToo many players");
	}
	return (false);
}
