/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commacount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:33:30 by ampjimen          #+#    #+#             */
/*   Updated: 2024/07/07 21:37:28 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_commacount(char *line)
{
	int	i;
	int	num_of_commas;

	i = 0;
	num_of_commas = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			num_of_commas++;
		i++;
	}
	if (num_of_commas != 2)
		return (false);
	return (true);
}
