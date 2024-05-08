/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end_resources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:27:39 by meow              #+#    #+#             */
/*   Updated: 2024/05/04 22:26:39 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	sl_free_all_game_memory(t_game_data *game)
{
	free(game->entities_count);
	free_map(game);
	free_objects(&game->objects, game->mlxptr);
	if (game->player)
		free_player(game);
	if (game->door)
		free_door(game);
}
