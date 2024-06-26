/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:31:23 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/08 02:50:01 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	sl_end_game_checking(t_game_data *game)
{
	if (game->coins_count == game->entities_count->collectibles)
	{
		mlx_put_image_to_window(
			game->mlxptr,
			game->winptr,
			game->door->other_sprite->imptr,
			game->door->position.y,
			game->door->position.x
			);
		game->door_status = DOOR_UNLOCKED;
	}
	if (game->status)
		mlx_loop_end(game->mlxptr);
}
