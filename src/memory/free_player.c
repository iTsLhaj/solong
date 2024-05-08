/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:24:48 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/08 02:50:01 by hmouhib          ###   ########.fr       */
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
