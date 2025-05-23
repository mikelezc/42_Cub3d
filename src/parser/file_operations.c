/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:18:50 by ampjimen          #+#    #+#             */
/*   Updated: 2024/07/07 21:18:51 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*cb_adjust_map_line(char *content, t_parse *data)
{
	int		i;
	int		content_len;
	char	*line;

	i = -1;
	content_len = data->line_size;
	line = malloc(sizeof(char) * content_len);
	if (line == NULL)
		cb_error_exit("Error:\nMalloc failed");
	while (content[++i] != '\0')
	{
		line[i] = content[i];
		if (content[i] == ' ')
			line[i] = '1';
	}
	while (i < content_len)
	{
		line[i - 1] = '1';
		i++;
	}
	line[content_len - 1] = '\0';
	return (line);
}

int	cb_check_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		cb_error_exit("Error: Can not open file");
		return (false);
	}
	close(fd);
	return (true);
}
