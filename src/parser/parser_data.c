/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:00:31 by ampjimen          #+#    #+#             */
/*   Updated: 2024/08/04 18:32:12 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cb_init_parse_data(t_parse *data)
{
	data->raw_map = NULL;
	data->no = ft_strdup("X");
	data->so = ft_strdup("X");
	data->we = ft_strdup("X");
	data->ea = ft_strdup("X");
	data->f_color[0] = -1;
	data->f_color[1] = -1;
	data->f_color[2] = -1;
	data->c_color[0] = -1;
	data->c_color[1] = -1;
	data->c_color[2] = -1;
	data->reading_pos = 0;
	data->map_length = 0;
	data->line_size = 0;
	data->error = 0;
}

int	cb_check_argv_cub(char *argv, t_parse *data, t_game *game)
{
	int	len;

	len = ft_strlen(argv);
	if (len > 4 && ft_strcmp(argv + len - 4, ".cub") == 0)
	{
		if (!cb_check_read_map(argv, data, game))
			return (false);
	}
	else
	{
		printf("Error:\nInvalid file format.\n");
		cb_input_help();
	}
	return (true);
}

t_parse	cb_parse_file(char *argv, t_game *game)
{
	t_parse	data;

	cb_init_parse_data(&data);
	cb_check_argv_cub(argv, &data, game);
	return (data);
}
