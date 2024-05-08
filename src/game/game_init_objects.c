/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:29:38 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/08 02:50:01 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static t_objects	*get_last(t_objects *root)
{
	if (root == NULL)
		return (NULL);
	while (root->next)
		root = root->next;
	return (root);
}

/**
 * @brief
 * 	add's a game object struct so i can store my game objs walls collectibles ...
 * @param game game struct
 * @return a pointer to the new alloced game objs struct ! else NULL
 */
void	*sl_add_obj(
	t_game_data *game,
	t_vect2 o_position,
	t_obj_type o_type,
	t_sprite *o_sprite
)
{
	t_objects	*current;

	current = (t_objects *)malloc(sizeof(t_objects));
	ft_bzero((void *)current, sizeof(t_objects));
	if (current == NULL)
		return (NULL);
	if (game->objects == NULL)
		game->objects = current;
	else
		get_last(game->objects)->next = current;
	current->position.x = o_position.x;
	current->position.y = o_position.y;
	current->type = o_type;
	current->sprite = o_sprite;
	return (current);
}
