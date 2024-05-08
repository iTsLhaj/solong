/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:57:16 by meow              #+#    #+#             */
/*   Updated: 2024/05/07 02:02:48 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <X11/keysym.h>

/* this one updates the player's position according to the passed keycode ! */
t_vect2	*player_update_position(int keycode, t_vect2 *current_position)
{
	t_vect2	*next_position;
	t_side	side;

	next_position = (t_vect2 *)malloc(sizeof(t_vect2));
	ft_bzero((void *)next_position, sizeof(t_vect2));
	if (next_position == NULL)
		return (NULL);
	side = ft_key2side(keycode);
	update_sidep(
		current_position,
		next_position,
		side
		);
	return (next_position);
}
