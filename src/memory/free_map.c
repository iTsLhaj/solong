/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:23:25 by meow              #+#    #+#             */
/*   Updated: 2024/05/04 22:23:31 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_map(t_game_data *game)
{
	int	i;

	i = 0;
	while (i < game->map->map_bounds->x)
		free(game->map->m_map[i++]);
	free(game->map->m_map);
	free(game->map->map_bounds);
	free(game->map);
}
