/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:41:33 by meow              #+#    #+#             */
/*   Updated: 2024/05/07 02:07:17 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * @brief check's if all map lines are the same !
 * @param line a line read from the game map !
 * @return wether the map lines length are equal !
 * @retval	false the previous provided line length
 * 			doesn't equal to the current line
 * @retval true they're equal go next ... map lines length check valid !
 */
static bool	sl_check_line_length(char *line)
{
	static int	llength = -1;

	if (line == NULL)
		return (false);
	if (llength < 0)
		llength = ft_strlen(line);
	else
	{
		if (line[ft_strlen(line) - 1] == '\n')
		{
			if (llength != ft_strlen(line))
				return (false);
			else
				return (true);
		}
		else
			llength = ft_strlen(line);
	}
	return (true);
}

/**
 * @brief check's if a certain game mep line contains a non allowed character
 * @param line a game map line read !
 * @return if a non allowed character is present in the provided line !
 * @retval false a non allowed character is present
 * @retval true all good ^^
 * @todo replace the j while logic below to a ft_strchr !
 */
static bool	sl_check_line_chars(char *line)
{
	int	i;

	if (line == NULL)
		return (false);
	i = 0;
	if (line[ft_strlen(line) - 1] == '\n')
	{
		while (line[i] && i < ft_strlen(line) - 1)
		{
			if (ft_strchr("01CEP", line[i]) == NULL)
				return (false);
			i++;
		}
	}
	else
	{
		while (line[i] && i < ft_strlen(line))
		{
			if (ft_strchr("01CEP", line[i]) == NULL)
				return (false);
			i++;
		}
	}
	return (true);
}

/**
 * @brief this function check's wether the map is valid !
 * @param mapfp the map file path
 * @return wether the map is valid or no (like diffrent line length !)
 * @retval true valid
 * @retval false invalid !
 */
static bool	sl_check_lines(const char *mapfp)
{
	char	*line;
	int		fd;
	bool	retv;

	retv = true;
	if (!sl_check_mapfile(mapfp))
		return (false);
	fd = open(mapfp, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (!sl_check_line_length(line) || !sl_check_line_chars(line))
			retv = false;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (retv);
}

/** @brief this function check's if the provided map is like a rectangle !
 *
 *	11111111111111111111
 *	10000000000000000001
 *	10000000000000000001
 *	10000000000000000001
 *	10000000000000000001
 *	11111111111111111111
 *
 *	bascially this is the required opts:
 *		- the first and last rows are all ones (1)
 *		- the other rows (all except 0 and map->map_bounds->x - 1)
 *		  are starting and ending with '1'
 * @param map the game map struct !
 * @return true if it's a rectangle false otherwise !
 */
static bool	sl_check_rectangle(t_map *map)
{
	int	i;

	i = 0;
	if (ft_all_ones(map->m_map[i]) == false
		|| ft_all_ones(map->m_map[map->map_bounds->x - 1]) == false)
		return (false);
	while (++i < map->map_bounds->x)
	{
		if (map->m_map[i][0] != '1' || map->m_map[i][
			map->map_bounds->y - 1] != '1')
			return (false);
	}
	if (map->map_bounds->x == map->map_bounds->y)
		return (false);
	return (true);
}

/**
 *
 * @param game game struct !
 * @return
 *	1 unknown error occured (allocation, file open ... etc !) not likely !
 *	0 if all tests went correct !
 *	-1 line length test failed !
 *	-2 the map isn't a rectangulare shape
 *	-3 the elements count of the map are invalid ! (like having 2 'P' !?)
 *	-4 the flood fill test failed !
 */
int	sl_check_map(t_game_data *game)
{
	bool	mapl;
	bool	maph;
	bool	ecount;
	bool	fftest;

	mapl = false;
	maph = false;
	ecount = false;
	fftest = false;
	mapl = sl_check_lines(game->map->mapfp);
	if (!mapl)
		return (1);
	maph = sl_check_rectangle(game->map);
	if (!maph)
		return (1);
	ecount = sl_map_ecount(game->map->mapfp, game);
	if (!ecount)
	{
		free(game->entities_count);
		return (1);
	}
	fftest = sl_flood_fill(game);
	if (!fftest)
		return (1);
	return (0);
}
