/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:35:28 by meow              #+#    #+#             */
/*   Updated: 2024/05/07 01:57:44 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_vect2	*get_player_pos(t_map *map)
{
	char	*p;
	int		i;
	int		found;
	t_vect2	*pp;

	i = 0;
	found = -1;
	while (map->m_map[++i])
	{
		p = ft_strchr(map->m_map[i], 'P');
		if (p != NULL)
		{
			found = 1;
			break ;
		}
	}
	if (!found)
		return (NULL);
	pp = (t_vect2 *)malloc(sizeof(t_vect2));
	ft_bzero((void *)pp, sizeof(t_vect2));
	if (pp == NULL)
		return (NULL);
	pp->x = i;
	pp->y = p - map->m_map[i];
	return (pp);
}

static void	flood_fill(
	t_game_data *game,
	t_claimed *objs,
	int x, int y)
{
	char	cur;

	if ((x > game->map->map_bounds->x)
		|| (x < 0)
		|| (y > game->map->map_bounds->y)
		|| (y < 0))
		return ;
	cur = game->map->m_map[x][y];
	if (cur == '-')
		return ;
	if (cur == '1')
		return ;
	if (cur == 'C')
		objs->collectibles++;
	if (cur == 'E')
		return ;
	game->map->m_map[x][y] = '-';
	flood_fill(game, objs, x + 1, y);
	flood_fill(game, objs, x - 1, y);
	flood_fill(game, objs, x, y + 1);
	flood_fill(game, objs, x, y - 1);
}

/**
 * this goes through all the map using a DFS algorithm
 * and check's if all coins and the exit are accessible to the player !
 * @param game game struct !
 * @return yes if all coins and the exit are accessible to the player !
 */
bool	sl_flood_fill(t_game_data *game)
{
	t_claimed	*inv;
	t_vect2		*player_pos_;

	inv = (t_claimed *)malloc(sizeof(t_claimed));
	ft_bzero((void *)inv, sizeof(t_claimed));
	if (inv == NULL)
		return (false);
	inv->collectibles = 0;
	inv->exit = 0;
	player_pos_ = get_player_pos(game->map);
	flood_fill(game, inv, player_pos_->x, player_pos_->y);
	if (inv->collectibles == game->entities_count->collectibles)
	{
		free(player_pos_);
		free(inv);
		return (true);
	}
	free(player_pos_);
	free(inv);
	return (false);
}
