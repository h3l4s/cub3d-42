SRCS		=	src/free.c \
		src/error.c \
		src/ft_atoi.c \
		src/ft_split.c \
		src/get_next_line.c \
		src/check.c \
		src/init.c \
		src/get_next_line_utils.c \
		src/parsing_map.c \
		src/open_game.c \
		src/move_player.c \
		src/ft_strcat.c \
		src/main.c \
		src/hook.c	\
		src/parsing_map2.c \
		src/parsing_map3.c \
		src/raycasting.c \
		src/split_temp.c \
		src/texture_draw.c \
		src/transform.c \

BSRCS 		= src_bonus/move_mous_bonus.c \
		src_bonus/free_bonus.c \
		src_bonus/error_bonus.c \
		src_bonus/ft_atoi_bonus.c \
		src_bonus/ft_split_bonus.c \
		src_bonus/get_next_line_bonus.c \
		src_bonus/check_bonus.c \
		src_bonus/init_bonus.c \
		src_bonus/get_next_line_utils_bonus.c \
		src_bonus/parsing_map_bonus.c \
		src_bonus/open_game_bonus.c \
		src_bonus/move_player_bonus.c \
		src_bonus/ft_strcat_bonus.c \
		src_bonus/main_bonus.c \
		src_bonus/hook_bonus.c	\
		src_bonus/parsing_map2_bonus.c \
		src_bonus/parsing_map3_bonus.c \
		src_bonus/raycasting_bonus.c \
		src_bonus/split_temp_bonus.c \
		src_bonus/texture_draw_bonus.c \
		src_bonus/transform_bonus.c \

OBJS 		= ${SRCS:.c=.o}

BOBJS		= $(BSRCS:.c=.o)

UNAME		:= $(shell uname)

CC 			= clang
CFLAGS		= -Wall -Wextra -Werror -g3
RM			= rm -f
NAME		= cub3d
NAMEBONUS	= cub3d_bonus
FLAGS		= -lXext -lX11 -lm libmlx.a libmlx_Linux.a

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

$(NAMEBONUS):	$(BOBJS)
				$(CC) $(CFLAGS) $(BOBJS) -o $(NAMEBONUS) $(FLAGS)

clean:
			${RM} ${OBJS} $(BOBJS)

fclean: 	clean
			${RM} ${NAME} $(NAMEBONUS)

bonus:		$(NAMEBONUS)

re: 		fclean all