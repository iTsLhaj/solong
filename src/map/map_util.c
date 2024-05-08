/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:47:14 by meow              #+#    #+#             */
/*   Updated: 2024/05/07 02:06:15 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 *	@brief this function test's the provided map file path for any error's
 *	@param mapfp map file path to check !
 *	@return wether the map file will face no error's when opening ... etc
 *	@retval false there will be error's
 *	@retval true there will be no error's all good !
 *	@note you could check the errno or use perror !
 *	@todo the line might be empty
 */
bool	sl_check_mapfile(const char *mapfp)
{
	int		fd;
	bool	empty;
	char	*line;

	empty = true;
	fd = open(mapfp, O_RDONLY);
	if (fd == -1)
	{
		ft_puterror("");
		perror("");
		return (false);
	}
	line = get_next_line(fd);
	while (line)
	{
		empty = false;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (empty)
		return (false);
	return (true);
}

static void	initialize_ec_struct(t_game_data *game)
{
	game->entities_count = (t_ecount *)malloc(sizeof(t_ecount));
	ft_bzero((void *)game->entities_count, sizeof(t_ecount));
	if (game->entities_count == NULL)
		return ;
	game->entities_count->collectibles = 0;
	game->entities_count->exit = 0;
	game->entities_count->player = 0;
	game->entities_count->walls = 0;
	game->entities_count->space = 0;
}

static int	check_ecgame(t_game_data *game)
{
	if (game == NULL)
		return (1);
	if (game->entities_count == NULL)
		return (1);
	return (0);
}

static void	fill_ec_struct(t_game_data *game, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == '0')
				game->entities_count->space++;
			else if (line[i] == '1')
				game->entities_count->walls++;
			else if (line[i] == 'E')
				game->entities_count->exit++;
			else if (line[i] == 'P')
				game->entities_count->player++;
			else if (line[i] == 'C')
				game->entities_count->collectibles++;
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
}

/**
 * @brief the 'E' count and 'P' count is exactly 1
 * @param mapfp game map file path
 * @return 'E' count and 'P' count is 1, true if yes otherwise false
 */
bool	sl_map_ecount(const char *mapfp, t_game_data *game)
{
	int		fd;

	if (!sl_check_mapfile(mapfp))
		return (false);
	fd = open(mapfp, O_RDONLY);
	initialize_ec_struct(game);
	if (check_ecgame(game))
		return (false);
	fill_ec_struct(game, fd);
	if (
		game->entities_count->player != 1
		|| game->entities_count->exit != 1
		|| game->entities_count->collectibles < 1)
		return (false);
	return (true);
}
