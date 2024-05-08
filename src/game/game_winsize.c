/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_winsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:31:01 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/08 02:50:01 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * @brief set's the game window size according to the game map size !
 * @param game game struct
 */
void	sl_set_window_size(t_game_data *game)
{
	if (game == NULL)
		return ;
	game->window_height = game->map->map_bounds->x * 48;
	game->window_width = game->map->map_bounds->y * 48;
}
