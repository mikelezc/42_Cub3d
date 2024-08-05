/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:45:08 by ampjimen          #+#    #+#             */
/*   Updated: 2024/08/05 15:41:18 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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

void	bonus_init_vars(t_game *game);

///////////////////////////////////PARSING//////////////////////////////////////

/* bonus_parser_data.c */
void	bonus_init_parse_data(t_parse *data);
int		bonus_check_argv_cub(char *argv, t_parse *data, t_game *game);
t_parse	bonus_parse_file(char *argv, t_game *game);

/* bonus_check_enclusure.c */
bool	bonus_check_player_area_enclosed(char **map, int size);

/* bonus_texture_validation.c */
int		bonus_flag_invalid_attr(char *line);
int		bonus_check_no_so_texture(char *line, t_parse *data);
int		bonus_check_we_ea_texture(char *line, t_parse *data);
int		bonus_check_texture_dir(char *line, t_parse *data);
int		bonus_check_valid_line(char *line, t_parse *data);

/* bonus_color_validation.c */
int		bonus_check_and_save_color(char *line, t_parse *data);
char	**bonus_split_rgb(char *line, char *trim_with);
int		bonus_check_valid_rgb(char **rgb);
int		bonus_check_duplicate_rgb(char *line);
int		bonus_check_invalid_rgb_chars(char *line);

/* bonus_file_operations.c */
char	*bonus_adjust_map_line(char *content, t_parse *data);
int		bonus_check_open_file(char *file);

/* bonus_map_init.c */
int		bonus_check_read_map(char *map_file, t_parse *data, t_game *game);
void	bonus_get_player_pos(char **map, t_game *game);
int		bonus_check_duplicate(char *line, t_parse *data);
int		bonus_check_and_init_map(t_parse *data, int i, t_game *game);

/* bonus_map_val_utils.c */
bool	bonus_is_all_digits(char *str);
bool	bonus_check_exec(t_parse *data, t_game *game, int i, char **tmp_map);

/* bonus_map_validation.c */
int		bonus_validate_and_process_map(t_parse *data, int fd, t_game *game);
void	bonus_length_map(char *line, int fd, char *map_file, t_parse *data);
int		bonus_check_only_spaces(char *line);
int		bonus_not_valid_map_char(char *line);
int		bonus_check_duplicate_players(char c, char option);

/* bonus_update_data.c */
void	bonus_update_color_data(char **rgb, t_parse *data, char option);
void	bonus_update_texture_data(char *file, t_parse *data, char option);

/* bonus_help.c */

void	bonus_input_help(void);

///////////////////////////////////GAME/////////////////////////////////////////

/* bonus_game_main.c */
void	bonus_image_to_window(t_game *game);
void	bonus_ceiling_floor(t_game *game);
int		bonus_game_loop(t_game *game);
void	bonus_zbuffer_init(t_game *game);
void	bonus_game_main(t_game *game, t_parse *data);

/* bonus_load_game.c */
void	bonus_get_int_color_fl_cel(t_game *game, t_parse *data);
void	bonus_load_texture(t_game *game, int *texture, \
		char *path, t_img *img);
void	bonus_load_img_wall(t_game *game, t_parse *data);
void	bonus_set_img_wall(t_game *game);
void	bonus_load_game(t_game *game, t_parse *data);

/* bonus_raycasting.c */
void	bonus_fill_zbuffer(t_game *game, t_raycast *vars, int x, int y);
void	bonus_dda(t_game *game, t_raycast *vars);
void	bonus_check_ray_collision(t_game *game, t_raycast *vars);
void	bonus_ray_trajectory(t_game *game, t_raycast *vars, int x);
void	bonus_raycasting(t_game *game);

/* bonus_raycasting_utils.c */
int		bonus_calculate_color(int color, double distance);
void	bonus_apply_door_texture(t_game *game, t_raycast *vars, int x, int y);
void	calculate_wall_and_texture_params(t_game *game, t_raycast *vars);
void	calculate_basic_raycast_params(t_game *game, t_raycast *vars);
void	bonus_render_3d_walls(t_game *game, t_raycast *vars, int x);

/* bonus_minimap.c */
void	bonus_put_miniplayer(t_game *game);
void	bonus_fill_minimap(t_game *game, int color, int x, int y);
void	bonus_put_minimap(t_game *game);
void	bonus_minimap(t_game *game);

/* bonus_minimap_utils.c */
void	bonus_draw_ray_on_minimap(t_game *game, t_raycast *vars, \
		int map_width, int map_height);
int		bonus_get_map_height(char **map);
int		bonus_get_map_width(char **map);
void	bonus_draw_rays(t_game *game);

/* bonus_cam_movements.c */
double	bonus_move_speed(t_game *game);
void	bonus_rotate_cam(t_game *game, t_player *p);
void	bonus_frwr_back_cam(t_game *game, t_player *p);
void	bonus_side_mov_cam(t_game *game, t_player *p);
void	bonus_cam_movements(t_game *game);

/* bonus_mouse_hooks.c */
int		bonus_mouse_click(int button, int x, int y, t_game *game);
int		bonus_mouse_move(int x, int y, t_game *game);

/* bonus_weapon.c */
void	bonus_snprintf(char *buffer, size_t size, char *format, int index);
void	bonus_render_weapon(t_weapon *weapon, t_game *game);
void	bonus_load_weapon_animation(t_game *game);
void	bonus_load_main_weapon(t_game *game);
void	bonus_load_img_weapon(t_game *game);

/* bonus_weapon_utils.c */
t_img	bonus_load_image(void *mlx, const char *path);
void	bonus_load_img_crack(t_game *game);
void	bonus_draw_image(void *mlx, void *win, const t_img *params);
void	bonus_draw_crack_frame(t_game *game);

/* bonus_keys_on_off.c */
int		bonus_key_off(int key, t_game *game);
int		bonus_key_on(int key, t_game *game);

/* bonus_exit_n_frees */
void	bonus_free_array(void **arr);
void	bonus_free_textures(int **array);
void	bonus_free_weapon_imgs(t_game *game);
int		bonus_exit(t_game *game);
void	bonus_error_exit(char *msg);

/* bonus_door.c */
void	bonus_handle_door_interact(t_game *game, int set_key_space);
int		bonus_calc_direction(float dir);
void	bonus_toggle_door_if_nearby(t_game *game, int check_x, int check_y);
void	bonus_toggle_door(t_game *game, int p_map_x, int p_map_y);

/* bonus_door_input.c */
void	bonus_calculate_door_position(t_game *game, t_door_params *params);
void	bonus_toggle_door_state(t_game *game, t_door_params *params);
void	bonus_door_input(t_game *game);

/* bonus_helper.c */
void	bonus_load_img_helper(t_game *game);
void	bonus_helper(t_game *game);

#endif