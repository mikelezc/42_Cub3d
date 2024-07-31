NAME = libft.a
GCC = gcc 
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR		= ./obj/
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_itoa.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_strmapi.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strjoin.c \
ft_strlen.c ft_strncmp.c ft_substr.c ft_strnstr.c ft_striteri.c \
ft_split.c ft_strtrim.c ft_strrchr.c ft_tolower.c ft_toupper.c \
get_next_line.c ft_strcmp.c ft_null_free.c get_line.c ft_isspace.c \
ft_commacount.c \

SRC_B = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJ_FILES = $(SRCS:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
OBJS		= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJS_BONUS = $(addprefix $(OBJ_DIR), $(OBJ_B))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(@D)
	@$(GCC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re