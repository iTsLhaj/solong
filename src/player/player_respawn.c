/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_respawn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:57:39 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/08 02:50:01 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	player_respawn(t_game_data *game)
{
	t_sprite	*sprite_;

	if (game->player_direction == 'r')
		sprite_ = game->player->other_sprite;
	else if (game->player_direction == 'l')
		sprite_ = game->player->sprite;
	else
		return ;
	mlx_put_image_to_window(
		game->mlxptr,
		game->winptr,
		sprite_->imptr,
		game->player->position.y, game->player->position.x
		);
}
