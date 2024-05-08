/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_keyclick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:32:49 by meow              #+#    #+#             */
/*   Updated: 2024/05/04 18:33:20 by meow             ###   ########.fr       */
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
