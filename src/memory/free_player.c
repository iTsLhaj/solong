/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:24:48 by meow              #+#    #+#             */
/*   Updated: 2024/05/04 22:25:34 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_player(t_game_data *game)
{
	if (game->player->sprite)
	{
		mlx_destroy_image(game->mlxptr, game->player->sprite->imptr);
		free(game->player->sprite);
	}
	if (game->player->other_sprite)
	{
		mlx_destroy_image(game->mlxptr, game->player->other_sprite->imptr);
		free(game->player->other_sprite);
	}
	free(game->player);
}
