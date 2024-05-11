/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:23:25 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/11 20:09:59 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_map(t_game_data *game)
{
	int	i;

	i = 0;
	while (i < game->map->map_bounds->x)
	{
		free(game->map->m_map[i]);
		free(game->map_clone[i]);
		i++;
	}
	free(game->map->m_map);
	free(game->map_clone);
	free(game->map->map_bounds);
	free(game->map);
}
