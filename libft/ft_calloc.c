/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:49:21 by ampjimen          #+#    #+#             */
/*   Updated: 2024/07/03 21:20:34 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*buffer;

	buffer = (void *)malloc(size * nitems);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, size * nitems);
	return (buffer);
}
