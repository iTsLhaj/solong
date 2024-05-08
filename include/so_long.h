/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:45:46 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/08 02:50:01 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <get_next_line.h>
# include <libftprintf.h>
# include <libft.h>
# include <types.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include <color.h>

/*** map\ ***/
bool		sl_check_mapfile(const char *mapfp);
bool		sl_map_ecount(const char *mapfp, t_game_data *game);
void		sl_set_map_bounds(t_game_data *game);
void		sl_free_all_map(t_game_data *game, int p);
void		sl_load_map(t_game_data *game, const char *mapfp_);
void		sl_draw_map(t_game_data *game);
int			sl_check_map(t_game_data *game);
bool		sl_flood_fill(t_game_data *game);
void		sl_render_map(t_game_data *game);
int			sl_map_setup(t_game_data *game, const char *av1);

/*** game\ ***/
void		sl_set_window_size(t_game_data *game);
void		*sl_add_obj(
				t_game_data *game,
				t_vect2 o_position,
				t_obj_type o_type,
				t_sprite *o_sprite
				);
void		sl_end_game(t_game_data *game);
void		sl_free_all_game_memory(t_game_data *game);
void		sl_game_init_values(t_game_data *game);
void		sl_game_renderer(
				t_game_data *game,
				t_obj_type type,
				t_vect2 *position
				);

/*** keyhook\ **/
void		update_sidep(t_vect2 *curp, t_vect2 *nextp, t_side s);
void		sl_end_game_checking(t_game_data *game);
void		on_keyclick_rituals(int keycode, t_game_data *game, t_vect2 *nextp);

/*** utils\ ***/
void		ft_puterror(char *msg);
t_obj_type	ft_get_entity_type(char c);
t_sprite	*ft_mksprite(t_obj_type type, void *mlxptr, char *impath_);
void		ft_fill_area(
				t_vect2 point,
				t_vect2 epoint,
				t_game_data *game,
				int color
				);
void		fill_background(t_game_data *game);
t_side		ft_key2side(int xkey);
int			ft_check_xpm_assets(void *mlxptr);

/*** player\ ***/
void		player_magically_vanished(t_game_data *game);
t_vect2		*player_update_position(int keycode, t_vect2 *current_position);
void		player_respawn(t_game_data *game);
bool		check_collision(t_game_data *game, t_vect2 *target_position);
bool		ft_all_ones(char *line);

/*** memory\ ***/
void		free_objects(t_objects **head_object, void *mlxptr);
void		free_map(t_game_data *game);
void		free_player(t_game_data *game);
void		free_door(t_game_data *game);

#endif
