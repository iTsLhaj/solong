/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:26:11 by meow              #+#    #+#             */
/*   Updated: 2024/05/04 22:26:57 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_door(t_game_data *game)
{
	if (game->door->sprite)
	{
		mlx_destroy_image(game->mlxptr, game->door->sprite->imptr);
		free(game->door->sprite);
	}
	if (game->door->other_sprite)
	{
		mlx_destroy_image(game->mlxptr, game->door->other_sprite->imptr);
		free(game->door->other_sprite);
	}
	free(game->door);
}
