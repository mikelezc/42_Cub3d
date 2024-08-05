/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:14:30 by mlezcano          #+#    #+#             */
/*   Updated: 2024/08/05 15:50:32 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "structs.h"
# include "macros.h"

///////////////////////////////////MAIN/////////////////////////////////////////

void	cb_init_vars(t_game *game);

///////////////////////////////////PARSING//////////////////////////////////////

/* parser_data.c */
void	cb_init_parse_data(t_parse *data);
int		cb_check_argv_cub(char *argv, t_parse *data, t_game *game);
t_parse	cb_parse_file(char *argv, t_game *game);

/* check_enclosure.c */
bool	cb_check_player_area_enclosed(char **map, int size);

/* texture_validdation.c */
int		cb_flag_invalid_attr(char *line);
int		cb_check_no_so_texture(char *line, t_parse *data);
int		cb_check_we_ea_texture(char *line, t_parse *data);
int		cb_check_texture_dir(char *line, t_parse *data);
int		cb_check_valid_line(char *line, t_parse *data);

/* color_validation.c */
int		cb_check_and_save_color(char *line, t_parse *data);
char	**cb_split_rgb(char *line, char *trim_with);
int		cb_check_valid_rgb(char **rgb);
int		cb_check_duplicate_rgb(char *line);
int		cb_check_invalid_rgb_chars(char *line);

/* file_operations.c */
char	*cb_adjust_map_line(char *content, t_parse *data);
int		cb_check_open_file(char *file);

/* map_init.c */
int		cb_check_read_map(char *map_file, t_parse *data, t_game *game);
void	cb_get_player_pos(char **map, t_game *game);
int		cb_check_duplicate(char *line, t_parse *data);
int		cb_check_and_init_map(t_parse *data, int i, t_game *game);

/* map_val_utils.c */
bool	cb_is_all_digits(char *str);
bool	cb_check_exec(t_parse *data, t_game *game, int i, char **tmp_map);

/* map_validation.c */
int		cb_validate_and_process_map(t_parse *data, int fd, t_game *game);
void	cb_length_map(char *line, int fd, char *map_file, t_parse *data);
int		cb_check_only_spaces(char *line);
int		cb_not_valid_map_char(char *line);
int		cb_check_duplicate_players(char c, char option);

/* update_data.c */
void	cb_update_color_data(char **rgb, t_parse *data, char option);
void	cb_update_texture_data(char *file, t_parse *data, char option);

/* help.c */

void	cb_input_help(void);

///////////////////////////////////GAME/////////////////////////////////////////

/* game_main.c */
void	cb_image_to_window(t_game *game);
void	cb_ceiling_floor(t_game *game);
int		cb_game_loop(t_game *game);
void	cb_zbuffer_init(t_game *game);
void	cb_game_main(t_game *game, t_parse *data);

/* load_game.c */
void	cb_get_int_color_fl_cel(t_game *game, t_parse *data);
void	cb_load_texture(t_game *game, int *texture, \
		char *path, t_img *img);
void	cb_load_img_wall(t_game *game, t_parse *data);
void	cb_set_img_wall(t_game *game);
void	cb_load_game(t_game *game, t_parse *data);

/* raycasting.c */
void	cb_fill_zbuffer(t_game *game, t_raycast *vars, int x, int y);
void	cb_dda(t_game *game, t_raycast *vars);
void	cb_check_ray_collision(t_game *game, t_raycast *vars);
void	cb_ray_trajectory(t_game *game, t_raycast *vars, int x);
void	cb_raycasting(t_game *game);

/* raycasting_utils.c */
int		cb_hex_to_int(const char *hex_str);
void	cb_render_3d_walls(t_game *game, t_raycast *vars);

/* cam_movements.c */
void	cb_rotate_cam(t_game *game, t_player *p);
void	cb_frwr_back_cam(t_game *game, t_player *p);
void	cb_side_mov_cam(t_game *game, t_player *p);
void	cb_cam_movements(t_game *game);

/* keys_on_off.c */
int		cb_key_off(int key, t_game *game);
int		cb_key_on(int key, t_game *game);

/* exit_n_frees */
void	cb_free_array(void **arr);
void	cb_free_textures(int **array);
int		cb_exit(t_game *game);
void	cb_error_exit(char *msg);

#endif