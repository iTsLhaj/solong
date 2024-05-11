/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:00:19 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/10 15:07:00 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <linux/limits.h>

typedef enum e_side
{
	UP,
	LEFT,
	DOWN,
	RIGHT,
	UNLISTED
}	t_side;

typedef enum e_object_type
{
	INVALID = -1,
	COLLECTIBLE,
	WALL,
	PLAYER,
	EMPTY,
	DOOR_LOCKED,
	DOOR_UNLOCKED,
	NONE
}	t_obj_type;

typedef struct s_claimed
{
	int	exit;
	int	collectibles;
}	t_claimed;

typedef struct s_entities_count
{
	int	player;
	int	exit;
	int	collectibles;
	int	walls;
	int	space;
}	t_ecount;

typedef struct s_vect2
{
	int	x; /* h */
	int	y; /* w */
}	t_vect2;

typedef struct s_map
{
	char	**m_map;
	char	mapfp[PATH_MAX];
	t_vect2	*map_bounds;
}	t_map;

typedef struct s_sprite
{
	void	*imptr;
	t_vect2	size;
}	t_sprite;

typedef struct s_objects
{
	t_obj_type			type;
	t_vect2				position;
	t_sprite			*sprite;
	struct s_objects	*next;
}	t_objects;

typedef struct s_object
{
	t_vect2		position;
	t_sprite	*sprite;
	t_sprite	*other_sprite;
}	t_object;

typedef struct s_game_data
{
	void		*mlxptr;
	void		*winptr;
	t_ecount	*entities_count;
	t_map		*map;
	char		**map_clone;
	int			window_height;
	int			window_width;
	t_objects	*objects;
	t_object	*player;
	t_object	*door;
	t_obj_type	door_status;
	char		player_direction;
	int			coins_count;
	int			status;
	int			moves;
	int			error_on_exit;
}	t_game_data;

#endif
