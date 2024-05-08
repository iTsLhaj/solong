/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_keyclick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:32:49 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/08 02:50:01 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	on_keyclick_rituals(int keycode, t_game_data *game, t_vect2 *nextp)
{
	nextp = player_update_position(
			keycode,
			&game->player->position
			);
	if (!check_collision(game, nextp))
	{
		free(nextp);
		return ;
	}
	game->moves++;
	ft_printf("moves done: %i\n", game->moves);
	player_magically_vanished(game);
	game->player->position.y = nextp->y;
	game->player->position.x = nextp->x;
	player_respawn(game);
	free(nextp);
}
