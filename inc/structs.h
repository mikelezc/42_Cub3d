/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 02:29:28 by ampjimen          #+#    #+#             */
/*   Updated: 2024/08/04 17:50:36 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	void		*img;
	int			x;
	int			y;
	int			*data;
	int			bg_color;
	int			size_l;
	int			bpp;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct s_map
{
	char		**map;
	int			floor_color;
	int			ceil_color;
	void		*n_wall;
	void		*s_wall;
	t_img		e_wall;
	t_img		w_wall;
	int			door_state;
	int			**visited;
	int			**door_open;
}				t_map;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_keys
{
	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_m;
	int			key_h;
	int			key_left;
	int			key_right;
	int			key_shift;
	int			key_space;
}				t_keys;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_keys		keys;
	t_img		img;
	t_player	player;
	t_map		map;
	int			minimap_on;
	int			help_on;
	t_img		help;
	int			click;
	t_img		weapon_img;
	t_img		weapon_imgs[4];
	t_img		crack_img;
	int			weapon_x;
	int			weapon_y;
	int			current_sprite;
	int			frame_count;
	int			crack_bg_color;
	int			**zbuffer;
	int			**texture;
}				t_game;

//raycasting struct
typedef struct t_raycast
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_end;
	int			draw_start;
	int			tex_num;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
}				t_raycast;

typedef struct s_parse
{
	int			reading_pos;
	int			error;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f_color[3];
	int			c_color[3];
	int			map_length;
	size_t		line_size;
	char		**raw_map;
}				t_parse;

typedef struct s_door_params
{
	int			player_map_x;
	int			player_map_y;
	int			door_x;
	int			door_y;
	int			dir_x;
	int			dir_y;
}				t_door_params;

#endif