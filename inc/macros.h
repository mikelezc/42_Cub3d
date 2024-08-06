/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:51:59 by mlezcano          #+#    #+#             */
/*   Updated: 2024/08/05 16:49:25 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/* Define the width and height of the textures */
# define TEXWIDTH			64
# define TEXHEIGHT			64

/* Define the width and height of the window */
# define W_WIDTH 			800
# define W_HEIGHT			600

/* Define darkness of the walls */
# define DARKNESS			"0x7F7F7F"

/* Definitions to xml hook */
# define KEY_ESC			65307
# define KEY_UP				65362
# define KEY_DOWN			65364
# define KEY_RIGHT			65363
# define KEY_LEFT			65361
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_M				109
# define KEY_H				104
# define KEY_SHIFT			65505
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define KEY_SPACE          32

/* Define mouse sensitivity */
# define MOUSE_SENSITIVITY	0.00055

/* Define cam speed */
# define MOVE_SPEED			0.04
# define ROT_SPEED			0.03

/* Minimap */
# define PLAYER_SIZE		5
# define MINIMAP_SCALE		10
# define PLAYER_COLOR		0x0000FF
# define WALL_COLOR			0xFFFFFF
# define SPACE_COLOR		0x000000
# define DOOR_COLOR_C       0xFF0000
# define DOOR_COLOR_O       0x00FF00
# define RAY_COLOR			0xA37BF8

/* Cam margin for collision */
# define FRNT_MARGIN 		0.5
# define SIDE_MARGIN 		0.25
# define BACK_MARGIN 		0.25

/*door texture*/
# define DOOR_TEXTURE		4

#endif