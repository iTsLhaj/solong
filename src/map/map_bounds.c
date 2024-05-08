/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bounds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:33:52 by meow              #+#    #+#             */
/*   Updated: 2024/05/07 02:28:16 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/** @brief this reads the map file in order to return it's size !*/
static void	fetch_map_size(const char *mapfp, int *w, int *h)
{
	char	*line;
	int		fd;

	fd = open(mapfp, O_RDONLY);
	if (fd == -1)
		return ;
	*h = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (*w == -1)
			*w = ft_strlen(line) - 1;
		*h += 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

/**
 *	@brief	this function set's the map bounds x/w (heigth, width)
 *			just the matrix size not the acctual window size in pixel
 *			but this matrix can help getting the window size !
 *	@todo	you gotta cpy the mapfp to the game->map->mapfp
 *			not doing this will cause an error likely a (SIGSEV) !
 *	@param game game struct !
 */
void	sl_set_map_bounds(t_game_data *game)
{
	int	fd;

	game->map->map_bounds = NULL;
	if (!sl_check_mapfile(game->map->mapfp))
		return ;
	game->map->map_bounds = (t_vect2 *)malloc(sizeof(t_vect2));
	ft_bzero((void *)game->map->map_bounds, sizeof(t_vect2));
	if (game->map->map_bounds == NULL)
		return ;
	game->map->map_bounds->y = -1;
	game->map->map_bounds->x = -1;
	fetch_map_size(
		game->map->mapfp,
		&game->map->map_bounds->y,
		&game->map->map_bounds->x
		);
}
