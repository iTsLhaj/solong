/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_vanish.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:57:52 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/15 00:37:38 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	player_magically_vanished(t_game_data *game)
{
	t_sprite	*filling;

	filling = ft_mksprite(
			EMPTY, game->mlxptr, NULL);
	mlx_put_image_to_window(
		game->mlxptr, game->winptr,
		filling->imptr,
		game->player->position.y,
		game->player->position.x
		);
	sl_add_obj(
		game,
		(t_vect2){-1, -1},
		EMPTY, filling
		);
}
