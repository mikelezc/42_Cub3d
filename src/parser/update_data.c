/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:19:32 by ampjimen          #+#    #+#             */
/*   Updated: 2024/07/10 17:03:36 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cb_update_texture_data(char *file, t_parse *data, char option)
{
	if (option == 'N')
	{
		free(data->no);
		data->no = ft_strdup(file);
	}
	if (option == 'S')
	{
		free(data->so);
		data->so = ft_strdup(file);
	}
	if (option == 'W')
	{
		free(data->we);
		data->we = ft_strdup(file);
	}
	if (option == 'E')
	{
		free(data->ea);
		data->ea = ft_strdup(file);
	}
	free(file);
}

void	cb_update_color_data(char **rgb, t_parse *data, char option)
{
	if (option == 'F')
	{
		data->f_color[0] = ft_atoi(rgb[0]);
		data->f_color[1] = ft_atoi(rgb[1]);
		data->f_color[2] = ft_atoi(rgb[2]);
	}
	else if (option == 'C')
	{
		data->c_color[0] = ft_atoi(rgb[0]);
		data->c_color[1] = ft_atoi(rgb[1]);
		data->c_color[2] = ft_atoi(rgb[2]);
	}
	cb_free_array((void **)rgb);
}
