/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:44:51 by ampjimen          #+#    #+#             */
/*   Updated: 2024/07/31 16:49:48 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

#define BLUE "\033[1;34m" 
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

void	bonus_input_help(void)
{
	printf(BLUE " _______________________________ \n" RESET);
	printf(BLUE "|                               |\n" RESET);
	printf(BLUE "|" RESET GREEN "   🕹️  The RETURN of NULL  🕹️"BLUE"\
	|\n" RESET);
	printf(BLUE "|" RESET GREEN " Use: ./cub3D maps/[map.cub]"BLUE"\
	|\n" RESET);
	printf(BLUE "|_______________________________|\n" RESET);
	exit(EXIT_FAILURE);
}
