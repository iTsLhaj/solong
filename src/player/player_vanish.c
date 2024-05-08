/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_vanish.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:57:52 by meow              #+#    #+#             */
/*   Updated: 2024/05/04 18:59:10 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_magically_vanished(t_game_data *game)
{
	ft_fill_area(
		game->player->position,
		(t_vect2){48, 48},
		game, 0xC2B280
		);
}
