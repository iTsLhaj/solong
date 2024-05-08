/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:12:09 by meow              #+#    #+#             */
/*   Updated: 2024/05/07 01:55:44 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	render_sprite(
	t_game_data *game,
	t_sprite *sprite_,
	t_vect2 *current_position
)
{
	mlx_put_image_to_window(
		game->mlxptr,
		game->winptr,
		sprite_->imptr,
		current_position->y, current_position->x
		);
}

static void	render_player(
	t_game_data *game,
	t_sprite *sprite_,
	t_vect2 *current_position
)
{
	game->player = (t_object *)malloc(sizeof(t_object));
	ft_bzero((void *)game->player, sizeof(t_object));
	game->player_direction = 'l';
	game->player->sprite = sprite_;
	game->player->position.y = current_position->y;
	game->player->position.x = current_position->x;
	game->player->other_sprite = ft_mksprite(
			NONE,
			game->mlxptr,
			"player/luffy-right.xpm"
			);
	if (game->player->other_sprite == NULL)
	{
		ft_puterror("invalid xpm file !\n");
		game->error_on_exit = 1;
		return ;
	}
	game->player->position.y = current_position->y;
	game->player->position.x = current_position->x;
}

static void	render_door(
	t_game_data *game,
	t_sprite *sprite_,
	t_vect2 *current_position
)
{
	game->door = (t_object *)malloc(sizeof(t_object));
	ft_bzero((void *)game->door, sizeof(t_object));
	game->door->sprite = sprite_;
	game->door->position.y = current_position->y;
	game->door->position.x = current_position->x;
	game->door->other_sprite = ft_mksprite(
			DOOR_UNLOCKED,
			game->mlxptr,
			NULL
			);
	if (game->door->other_sprite == NULL)
	{
		ft_puterror("invalid xpm file !\n");
		game->error_on_exit = 1;
		return ;
	}
	game->door->position.y = current_position->y;
	game->door->position.x = current_position->x;
}

void	sl_game_renderer(
	t_game_data *game,
	t_obj_type type,
	t_vect2 *position
)
{
	t_sprite	*sprite_;

	sprite_ = ft_mksprite(type, game->mlxptr, NULL);
	if (sprite_ == NULL)
	{
		ft_puterror("invalid xpm file !\n");
		game->error_on_exit = 1;
		return ;
	}
	if (type == WALL || type == COLLECTIBLE)
		sl_add_obj(
			game,
			*position,
			type,
			sprite_
			);
	else if (type == PLAYER)
		render_player(game, sprite_, position);
	else if (type == DOOR_LOCKED)
		render_door(game, sprite_, position);
	if (type != INVALID && type != EMPTY)
		render_sprite(game, sprite_, position);
	position->y += sprite_->size.y;
}
