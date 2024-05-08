/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:53:24 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/08 02:50:01 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static bool	itter_objects(t_game_data *game, t_vect2 *target_position)
{
	t_objects	*current;

	current = game->objects;
	while (current)
	{
		if (
			target_position->y == current->position.y
			&& target_position->x == current->position.x
		)
		{
			if (current->type == WALL)
				return (false);
			else if (current->type == COLLECTIBLE)
			{
				current->position.x = -1;
				current->position.y = -1;
				game->coins_count += 1;
				return (true);
			}
		}
		else
			current = current->next;
	}
	return (true);
}

/* i'll return true if the player is allowed to move else false */
bool	check_collision(t_game_data *game, t_vect2 *target_position)
{
	if (!itter_objects(game, target_position))
		return (false);
	if (
		target_position->y == game->door->position.y
		&& target_position->x == game->door->position.x
	)
	{
		if (game->door_status == DOOR_LOCKED)
			return (false);
		else
		{
			game->status = 1;
			return (true);
		}
	}
	return (true);
}
