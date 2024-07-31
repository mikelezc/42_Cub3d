/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:38:54 by ampjimen          #+#    #+#             */
/*   Updated: 2024/07/08 19:09:11 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cb_check_valid_line(char *line, t_parse *data)
{
	if (ft_strcmp(data->no, "X") && ft_strcmp(data->so, "X")
		&& ft_strcmp(data->we, "X") && ft_strcmp(data->ea, "X")
		&& data->f_color[0] != -1 && data->c_color[0] != -1)
		return (true);
	if (cb_flag_invalid_attr(line) || cb_check_duplicate(line, data))
		return (false);
	if (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0)
		if (cb_check_texture_dir(line, data) == false)
			return (false);
	if ((ft_strncmp(line, "F ", 2) == 0) || (ft_strncmp(line, "C ", 2) == 0))
	{
		if (cb_check_and_save_color(line, data) == false)
			return (false);
	}
	else
		return (false);
	return (false);
}

int	cb_flag_invalid_attr(char *line)
{
	int	flag;

	flag = 0;
	if (line[0] != '\n'
		&& ft_strncmp(line, "NO", 2) != 0
		&& ft_strncmp(line, "SO", 2) != 0
		&& ft_strncmp(line, "WE", 2) != 0
		&& ft_strncmp(line, "EA", 2) != 0
		&& ft_strncmp(line, "F", 1) != 0
		&& ft_strncmp(line, "C", 1) != 0)
		flag++;
	if (flag != 0)
		cb_error_exit("Error:\nWrong attributes");
	return (false);
}

int	cb_check_texture_dir(char *line, t_parse *data)
{
	if (cb_check_no_so_texture(line, data) == false
		|| cb_check_we_ea_texture(line, data) == false)
		return (false);
	return (true);
}

int	cb_check_no_so_texture(char *line, t_parse *data)
{
	char	*file;

	if (ft_strncmp(line, "NO", 2) == 0)
	{
		file = ft_strtrim(line, "NO \n");
		if (cb_check_open_file(file) == true)
			cb_update_texture_data(file, data, 'N');
		else
			return (free(file), false);
	}
	if (ft_strncmp(line, "SO", 2) == 0)
	{
		file = ft_strtrim(line, "SO \n");
		if (cb_check_open_file(file) == true)
			cb_update_texture_data(file, data, 'S');
		else
			return (free(file), false);
	}
	return (true);
}

int	cb_check_we_ea_texture(char *line, t_parse *data)
{
	char	*file;

	if (ft_strncmp(line, "WE", 2) == 0)
	{
		file = ft_strtrim(line, "WE \n");
		if (cb_check_open_file(file) == true)
			cb_update_texture_data(file, data, 'W');
		else
			return (free(file), false);
	}
	if (ft_strncmp(line, "EA", 2) == 0)
	{
		file = ft_strtrim(line, "EA \n");
		if (cb_check_open_file(file) == true)
			cb_update_texture_data(file, data, 'E');
		else
			return (free(file), false);
	}
	return (true);
}
