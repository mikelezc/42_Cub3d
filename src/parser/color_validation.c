/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:39:05 by ampjimen          #+#    #+#             */
/*   Updated: 2024/08/04 18:40:56 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cb_check_and_save_color(char *line, t_parse *data)
{
	char	**rgb;

	if (!ft_commacount(line) || cb_check_invalid_rgb_chars(line)
		|| cb_check_duplicate_rgb(line))
		return (false);
	if (line[0] == 'F' || line[0] == 'C')
	{
		rgb = cb_split_rgb(line, " \n");
		if (cb_check_valid_rgb(rgb))
			cb_update_color_data(rgb, data, line[0]);
		else
			return (cb_free_array((void **)rgb), false);
	}
	return (true);
}

char	**cb_split_rgb(char *line, char *trim_with)
{
	char	*cut_line;
	char	**rgb;

	cut_line = ft_strtrim(line + 1, trim_with);
	rgb = ft_split(cut_line, ',');
	free(cut_line);
	return (rgb);
}

int	cb_check_duplicate_rgb(char *line)
{
	static int	f;
	static int	c;

	f = 0;
	c = 0;
	if (line[0] == 'F')
		f++;
	else if (line[0] == 'C')
		c++;
	else if (f != 1 || c != 1)
		cb_error_exit("Error:\nRGB duplicate value");
	return (false);
}

int	cb_check_valid_rgb(char **rgb)
{
	if (!cb_is_all_digits(rgb[0]) || !cb_is_all_digits(rgb[1]) \
		|| !cb_is_all_digits(rgb[2]))
		cb_error_exit("Error:\nInvalid RGB");
	if ((ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[0]) < 0)
		|| (ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[1]) < 0)
		|| (ft_atoi(rgb[2]) > 255 || ft_atoi(rgb[2]) < 0))
		cb_error_exit("Error:\nRGB Out of range");
	return (true);
}

int	cb_check_invalid_rgb_chars(char *line)
{
	size_t	i;

	i = 2;
	while (i < ft_strlen(line) - 1)
	{
		if (line[i] == ' ' || line[i] == ',' || ft_isdigit(line[i]))
			i++;
		else
			return (true);
	}
	return (false);
}
