/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:25:49 by ampjimen          #+#    #+#             */
/*   Updated: 2023/09/18 18:33:56 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*buffer;
	int		pos;

	pos = 0;
	buffer = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (s[pos])
	{
		buffer[pos] = s[pos];
		pos++;
	}
	buffer[pos] = '\0';
	return (buffer);
}
