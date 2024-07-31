/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_update_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:19:32 by ampjimen          #+#    #+#             */
/*   Updated: 2024/07/22 20:16:28 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	bonus_update_texture_data(char *file, t_parse *data, char option)
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

void	bonus_update_color_data(char **rgb, t_parse *data, char option)
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
	bonus_free_array((void **)rgb);
}
