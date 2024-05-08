# --- Variables --- #
NAME	=	so_long
LIBDIR	=	lib
INCDIR	=	include/

# --- Compiler --- #
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
LFLAGS	=	-lmlx -lXext -lX11
LIBS	=	$(LIBDIR)/lft/libft.a		\
			$(LIBDIR)/ptf/libftprintf.a

# --- Src Files --- #
FILES	=	lib/gnl/get_next_line.c			\
			lib/gnl/get_next_line_utils.c	\
			src/map/map_test.c				\
			src/map/map_util.c				\
			src/utils/ft_puterror.c			\
			src/map/map_load.c				\
			src/map/map_bounds.c			\
			src/map/map_alloc.c				\
			src/map/map_flood_fill.c		\
			src/map/map_render.c			\
			src/game/game_winsize.c			\
			src/game/game_init_objects.c	\
			src/utils/ft_get_entity_type.c	\
			src/utils/ft_make_sprite.c		\
			src/utils/ft_sketch.c			\
			src/player/player_vanish.c		\
			src/player/player_positions.c	\
			src/player/player_respawn.c		\
			src/player/player_collision.c	\
			src/game/game_end.c				\
			src/game/game_end_resources.c	\
			src/game/game_initv.c			\
			src/map/map_setup.c				\
			src/keyhook/key_positions.c		\
			src/utils/ft_key_to_side.c		\
			src/keyhook/end_checking.c		\
			src/keyhook/on_keyclick.c		\
			src/utils/ft_all_ones.c			\
			src/game/game_renderer.c		\
			src/memory/free_objects.c		\
			src/memory/free_map.c			\
			src/memory/free_player.c		\
			src/memory/free_door.c			\
			src/main.c

all: build_libs $(NAME)

$(NAME): $(FILES)
	@$(CC) -I $(INCDIR) $(FILES) $(LIBS) $(LFLAGS) -o $(NAME)

build_libs:
	@make -C $(LIBDIR)/lft
	@make -C $(LIBDIR)/ptf

clean_libs:
	@make -C $(LIBDIR)/lft clean
	@make -C $(LIBDIR)/ptf clean

clean: clean_libs

fclean:
	@make -C $(LIBDIR)/lft fclean
	@make -C $(LIBDIR)/ptf fclean
	@rm -f $(NAME)
