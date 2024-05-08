/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:30:40 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/08 02:50:01 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	sl_game_init_values(t_game_data *game)
{
	game->moves = 0;
	game->coins_count = 0;
	game->door_status = DOOR_LOCKED;
	game->objects = NULL;
	game->status = 0;
	game->mlxptr = mlx_init();
	game->error_on_exit = 0;
	if (game->mlxptr == NULL)
	{
		game->error_on_exit = 1;
		return ;
	}
	game->winptr = mlx_new_window(
			game->mlxptr, game->window_width,
			game->window_height, "so_long");
	if (game->winptr == NULL)
	{
		free(game->mlxptr);
		return ;
	}
	fill_background(game);
}
