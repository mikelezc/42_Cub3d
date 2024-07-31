/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parser_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:00:31 by ampjimen          #+#    #+#             */
/*   Updated: 2024/07/22 20:15:50 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	bonus_init_parse_data(t_parse *data)
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

int	bonus_check_argv_cub(char *argv, t_parse *data, t_game *game)
{
	int	len;

	len = ft_strlen(argv);
	if (len > 4 && ft_strcmp(argv + len - 4, ".cub") == 0)
	{
		if (bonus_check_read_map(argv, data, game) == false)
			return (false);
	}
	else
	{
		printf("Error:\nInvalid file format.\n");
		bonus_input_help();
	}
	return (true);
}

void	bonus_print_2d_array(char **array_2d)
{
	int	i;
	int	k;

	if (array_2d == NULL)
		return ;
	i = 0;
	while (array_2d[i] != NULL)
	{
		k = 0;
		while (array_2d[i][k] != '\0')
			ft_putchar_fd(array_2d[i][k++], 1);
		write(1, "\n", 2);
		i++;
	}
}

t_parse	bonus_parse_file(char *argv, t_game *game)
{
	t_parse	data;

	bonus_init_parse_data(&data);
	bonus_check_argv_cub(argv, &data, game);
	return (data);
}
