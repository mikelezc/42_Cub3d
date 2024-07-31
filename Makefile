# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/26 06:34:45 by mlezcano          #+#    #+#              #
#    Updated: 2024/07/29 07:30:06 by mlezcano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
GCC         	= gcc
RM          	= rm -f
DEBUG    		= -fsanitize=address -g3
IFLAGS      	= -I $(INC_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)
CFLAGS      	= -Wall -Werror -Wextra $(DEBUG) $(IFLAGS)
MFLAGS      	= -L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
LFLAGS      	= -L $(LIBFT_DIR) -lft

# Output
NAME        	= cub3D
NAME_BONUS  	= cub3D_bonus

# Directories
SRCS_DIR    	= ./src/
OBJ_DIR     	= ./obj/
INC_DIR    		= ./inc/
BONUS_DIR   	= ./bonus/

# Libft
LIBFT_DIR   	= libft
LIBFT_MAKE  	= Makefile
LIBFT_PATH  	= ${LIBFT_DIR}/libft.a

# Minilibx
MLX_DIR     	= ./minilibx-linux
MLX_MAKE    	= Makefile
MLX_PATH    	= ${MLX_DIR}/libmlx.a

# Source files
SRCS        	= main.c \
              	game/cam_movements.c \
              	game/exit_n_frees.c \
              	game/game_main.c \
             	game/keys_on_off.c \
              	game/load_game.c \
             	game/raycasting.c \
             	game/raycasting_utils.c \
              	parser/check_enclosure.c \
              	parser/color_validation.c \
              	parser/file_operations.c \
              	parser/map_init.c \
              	parser/map_val_utils.c \
              	parser/map_validation.c \
              	parser/parser_data.c \
              	parser/texture_validation.c \
              	parser/update_data.c \
              	parser/help.c

BONUS_SRCS		= main_bonus.c \
              	game_bonus/bonus_raycasting.c \
              	game_bonus/bonus_raycasting_utils.c \
              	game_bonus/bonus_minimap.c \
              	game_bonus/bonus_minimap_utils.c \
              	game_bonus/bonus_load_game.c \
              	game_bonus/bonus_game_main.c \
             	game_bonus/bonus_cam_movements.c \
              	game_bonus/bonus_keys_on_off.c \
              	game_bonus/bonus_exit_n_frees.c \
              	game_bonus/bonus_mouse_hooks.c \
              	game_bonus/bonus_weapon.c \
              	game_bonus/bonus_weapon_utils.c \
              	game_bonus/bonus_door.c \
              	game_bonus/bonus_door_input.c \
				game_bonus/bonus_helper.c \
              	parser_bonus/bonus_check_enclosure.c \
              	parser_bonus/bonus_color_validation.c \
              	parser_bonus/bonus_file_operations.c \
              	parser_bonus/bonus_map_init.c \
              	parser_bonus/bonus_map_val_utils.c \
              	parser_bonus/bonus_map_validation.c \
              	parser_bonus/bonus_parser_data.c \
              	parser_bonus/bonus_texture_validation.c \
              	parser_bonus/bonus_update_data.c \
              	parser_bonus/bonus_help.c

# Object files
OBJ_FILES       = $(SRCS:.c=.o)
BONUS_OBJ_FILES	= $(BONUS_SRCS:.c=.o)
SRC             = $(addprefix $(SRCS_DIR), $(SRCS))
BONUS_SRC       = $(addprefix $(BONUS_DIR), $(BONUS_SRCS))
OBJS            = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
BONUS_OBJS      = $(addprefix $(OBJ_DIR), $(BONUS_OBJ_FILES))
INCLUDES        = $(INC_DIR)

# Colors
BLACK  			= "\033[1;30m"
RED     		= "\033[1;31m"
GREEN   		= "\033[1;32m"
PURPLE  		= "\033[1;35m"
CYAN    		= "\033[1;36m"
WHITE   		= "\033[1;37m"
EOC     		= "\033[0;0m"

# Rules
all:	$(OBJ_DIR) $(NAME)

bonus:	$(OBJ_DIR) $(NAME_BONUS)

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES)
				@mkdir -p $(@D)
				@$(GCC) $(CFLAGS) -c $< -o $@
				@echo $(PURPLE) " - Compiling" $(GREEN) "$<" $(EOC)

$(OBJ_DIR)%.o: $(BONUS_DIR)%.c $(INCLUDES)
				@mkdir -p $(@D)
				@$(GCC) $(CFLAGS) -c $< -o $@
				@echo $(PURPLE) " - Compiling" $(GREEN) "$<" $(EOC)

$(NAME): $(OBJS)
				@echo $(PURPLE) " - Compiling" $(GREEN) "minilibx" $(EOC)
				@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
				@echo $(PURPLE) " - Compiling" $(GREEN) "libft" $(EOC)
				@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1
				@echo $(PURPLE) " - Linking   "$(GREEN) "$@" $(EOC)
				@$(GCC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME) $(MFLAGS)
				@echo $(IMG_MSG)
				@echo "- All rights reserved. © 2024 ampjimen & mlezcano corporation. - Enjoy the game!\n"

$(NAME_BONUS): $(BONUS_OBJS)
				@echo $(PURPLE) " - Compiling" $(GREEN) "minilibx" $(EOC)
				@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
				@echo $(PURPLE) " - Compiling" $(GREEN) "libft" $(EOC)
				@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1
				@echo $(PURPLE) " - Linking  " $(GREEN) "$@" $(EOC)
				@$(GCC) $(CFLAGS) $(BONUS_OBJS) $(LFLAGS) -o $(NAME_BONUS) $(MFLAGS)
				@echo $(IMG_MSG)
				@echo $(IMG_EXT)
				@echo "- All rights reserved. © 2024 ampjimen & mlezcano corporation. -"
				@echo "  Bonus mode enabled. Enjoy the game!  \n"

clean:
				@$(RM) $(OBJS) $(BONUS_OBJS)
				@$(RM) -r $(OBJ_DIR)
				@$(MAKE) -C $(LIBFT_DIR) -f $(LIBFT_MAKE) clean > /dev/null 2>&1
				@$(MAKE) -C $(MLX_DIR) -f $(MLX_MAKE) clean > /dev/null 2>&1
				@echo $(PURPLE)"  - Objects    "$(GREEN)"cleaned!" $(EOC)

fclean: clean
				@$(MAKE) -C $(LIBFT_DIR) -f $(LIBFT_MAKE) fclean > /dev/null 2>&1
				@$(RM) $(NAME) $(NAME_BONUS) > /dev/null 2>&1
				@echo $(PURPLE)"  - Executable "$(GREEN)"cleaned!" $(EOC)

re: fclean all

re_bonus: fclean bonus

# Message
IMG_MSG := $(PURPLE) "																											\n\
																																\n\
▓█████  ██▓        ██▀███  ▓█████▄▄▄█████▓ █    ██  ██▀███   ███▄    █    ▓█████▄ ▓█████     ███▄    █  █    ██  ██▓     ██▓    \n\
▓█   ▀ ▓██▒       ▓██ ▒ ██▒▓█   ▀▓  ██▒ ▓▒ ██  ▓██▒▓██ ▒ ██▒ ██ ▀█   █    ▒██▀ ██▌▓█   ▀     ██ ▀█   █  ██  ▓██▒▓██▒    ▓██▒    \n\
▒███   ▒██░       ▓██ ░▄█ ▒▒███  ▒ ▓██░ ▒░▓██  ▒██░▓██ ░▄█ ▒▓██  ▀█ ██▒   ░██   █▌▒███      ▓██  ▀█ ██▒▓██  ▒██░▒██░    ▒██░    \n\
▒▓█  ▄ ▒██░       ▒██▀▀█▄  ▒▓█  ▄░ ▓██▓ ░ ▓▓█  ░██░▒██▀▀█▄  ▓██▒  ▐▌██▒   ░▓█▄   ▌▒▓█  ▄    ▓██▒  ▐▌██▒▓▓█  ░██░▒██░    ▒██░    \n\
░▒████▒░██████▒   ░██▓ ▒██▒░▒████▒ ▒██▒ ░ ▒▒█████▓ ░██▓ ▒██▒▒██░   ▓██░   ░▒████▓ ░▒████▒   ▒██░   ▓██░▒▒█████▓ ░██████▒░██████▒\n"$(GREEN)"\
░░ ▒░ ░░ ▒░▓  ░   ░ ▒▓ ░▒▓░░░ ▒░ ░ ▒ ░░   ░▒▓▒ ▒ ▒ ░ ▒▓ ░▒▓░░ ▒░   ▒ ▒     ▒▒▓  ▒ ░░ ▒░ ░   ░ ▒░   ▒ ▒ ░▒▓▒ ▒ ▒ ░ ▒░▓  ░░ ▒░▓  ░\n\
 ░ ░  ░░ ░ ▒  ░     ░▒ ░ ▒░ ░ ░  ░   ░    ░░▒░ ░ ░   ░▒ ░ ▒░░ ░░   ░ ▒░    ░ ▒  ▒  ░ ░  ░   ░ ░░   ░ ▒░░░▒░ ░ ░ ░ ░ ▒  ░░ ░ ▒  ░\n\
   ░     ░ ░        ░░   ░    ░    ░       ░░░ ░ ░   ░░   ░    ░   ░ ░     ░ ░  ░    ░         ░   ░ ░  ░░░ ░ ░   ░ ░     ░ ░   \n\
 ░  ░    ░  ░      ░        ░  ░          ░        ░              ░       ░       ░  ░            ░    ░         ░  ░    ░  ░	\n\
                                                                          ░                                                     \
"
IMG_EXT := $(PURPLE) "	\n\
▓█████ ▒██   ██▒▄▄▄█████▓▓█████ ███▄    █ ▓█████▄ ▓█████ ▓█████▄ \n\
▓█   ▀ ▒▒ █ █ ▒░▓  ██▒ ▓▒▓█   ▀ ██ ▀█   █ ▒██▀ ██▌▓█   ▀ ▒██▀ ██▌\n\
▒███   ░░  █   ░▒ ▓██░ ▒░▒███  ▓██  ▀█ ██▒░██   █▌▒███   ░██   █▌\n\
▒▓█  ▄  ░ █ █ ▒ ░ ▓██▓ ░ ▒▓█  ▄▓██▒  ▐▌██▒░▓█▄   ▌▒▓█  ▄ ░▓█▄   ▌\n\
░▒████▒▒██▒ ▒██▒  ▒██▒ ░ ░▒████▒██░   ▓██░░▒████▓ ░▒████▒░▒████▓ \n"$(GREEN)"\
░░ ▒░ ░▒▒ ░ ░▓ ░  ▒ ░░   ░░ ▒░ ░ ▒░   ▒ ▒  ▒▒▓  ▒ ░░ ▒░ ░ ▒▒▓  ▒ \n\
 ░ ░  ░░░   ░▒ ░    ░     ░ ░  ░ ░░   ░ ▒░ ░ ▒  ▒  ░ ░  ░ ░ ▒  ▒ \n\
   ░    ░    ░    ░         ░     ░   ░ ░  ░ ░  ░    ░    ░ ░  ░ \n\
   ░  ░ ░    ░              ░  ░        ░    ░       ░  ░   ░    \n\
                                           ░              ░      \
"                                                                       

# Ensure this rule runs
.PHONY: all clean fclean re bonus re_bonus banner
