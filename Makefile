CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBS = lib/ptf/libftprintf.a lib/lft/libft.a
LMLX = -lmlx -lXext -lX11
SRC = lib/gnl/get_next_line.c			\
	  lib/gnl/get_next_line_utils.c		\
	  src/map/map_test.c				\
	  src/map/map_util.c				\
	  src/utils/ft_puterror.c			\
	  src/map/map_load.c				\
	  src/map/map_bounds.c				\
	  src/map/map_alloc.c				\
	  src/map/map_flood_fill.c			\
	  src/map/map_render.c				\
	  src/game/game_winsize.c			\
	  src/game/game_init_objects.c		\
	  src/utils/ft_get_entity_type.c	\
	  src/utils/ft_make_sprite.c		\
	  src/utils/ft_sketch.c				\
	  src/player/player_vanish.c		\
	  src/player/player_positions.c		\
	  src/player/player_respawn.c		\
	  src/player/player_collision.c		\
	  src/game/game_end.c				\
	  src/game/game_end_resources.c		\
	  src/game/game_initv.c				\
	  src/map/map_setup.c				\
	  src/keyhook/key_positions.c		\
	  src/utils/ft_key_to_side.c		\
	  src/keyhook/end_checking.c		\
	  src/keyhook/on_keyclick.c			\
	  src/utils/ft_all_ones.c			\
	  src/game/game_renderer.c			\
	  src/memory/free_objects.c			\
	  src/memory/free_map.c				\
	  src/memory/free_player.c			\
	  src/memory/free_door.c			\
	  src/main.c

OBJ = ${SRC:.c=.o}

NAME = so_long

all: mklibs ${NAME}

mklibs:
	@make -C lib/lft
	@make -C lib/ptf

${NAME}: ${LIBS} ${OBJ}
	${CC} -I include/ ${CFLAGS} $^ -o $@ ${LIBS} ${LMLX}

%.o: %.c
	${CC} -I include/ ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJ}
	@make -C lib/lft clean
	@make -C lib/ptf clean

fclean:
	${RM} ${OBJ} ${NAME}
	@make -C lib/lft fclean
	@make -C lib/ptf fclean

re: fclean ${NAME}
