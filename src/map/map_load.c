/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:24:06 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/16 17:32:34 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static char	*allocate_line(const char *line)
{
	char	*map_line;

	map_line = (char *)malloc(
			sizeof(char) * (ft_strlen(line) + 1));
	if (map_line == NULL)
		return (NULL);
	ft_bzero((void *)map_line,
		(sizeof(char) * (ft_strlen(line) + 1)));
	return (map_line);
}

static void	read_map(t_game_data *game)
{
	int		i;
	int		fd;
	char	*line;
	size_t	size;

	i = 0;
	fd = open(game->map->mapfp, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		game->map->m_map[i] = allocate_line(line);
		if (game->map->m_map[i] == NULL)
		{
			free(line);
			sl_free_all_map(game, i);
			break ;
		}
		size = ft_strlen(line) + 1;
		ft_strlcpy(game->map->m_map[i], line, size);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

static void	clone_map(t_game_data *game)
{
	int	i;

	game->map_clone = (char **)malloc(
			sizeof(char *) * game->map->map_bounds->x);
	ft_bzero((void *)game->map_clone,
		(sizeof(char *) * game->map->map_bounds->x));
	i = -1;
	while (++i < game->map->map_bounds->x)
		game->map_clone[i] = ft_strdup(game->map->m_map[i]);
}

/**
 * @brief it takes care of the map allocation !
 * @param game game struct !
 * @param mapfp_ game map file path !
 */
void	sl_load_map(t_game_data *game, const char *mapfp_)
{
	game->map = (t_map *)malloc(sizeof(t_map));
	ft_bzero((void *)game->map, sizeof(t_map));
	if (game->map == NULL)
		return ;
	if (sl_check_mapfext((char *)mapfp_, (void *)game->map))
		exit(1);
	ft_strlcpy(game->map->mapfp, mapfp_, PATH_MAX);
	if (!sl_check_mapfile(game->map->mapfp))
	{
		free(game->map);
		game->error_on_exit = 1;
		game->map = NULL;
		return ;
	}
	sl_set_map_bounds(game);
	game->map->m_map = (char **)malloc(
			sizeof(char *) * game->map->map_bounds->x);
	if (game->map->m_map == NULL)
		return ;
	ft_bzero((void *)game->map->m_map,
		(sizeof(char *) * game->map->map_bounds->x));
	read_map(game);
	clone_map(game);
}
