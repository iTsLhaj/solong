/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:24:06 by meow              #+#    #+#             */
/*   Updated: 2024/05/04 18:33:44 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/** @brief it free's the allocated map ! */
void	sl_free_all_map(t_game_data *game, int p)
{
	while (--p > -1)
		free(game->map->m_map[p]);
}
