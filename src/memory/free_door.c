/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:26:11 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/08 02:50:01 by hmouhib          ###   ########.fr       */
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
