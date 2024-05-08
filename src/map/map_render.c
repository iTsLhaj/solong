/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:03:45 by meow              #+#    #+#             */
/*   Updated: 2024/05/07 02:00:55 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	render_line(
	char *line,
	t_vect2 *current_position,
	t_game_data *game
)
{
	int			i;
	t_obj_type	type_;

	i = 0;
	while (line[i])
	{
		type_ = ft_get_entity_type(line[i]);
		if (line[i] == '\n' && type_ == INVALID)
			break ;
		if (line[i] == '0')
			current_position->y += 48;
		else if (type_ != INVALID && type_ != EMPTY)
			sl_game_renderer(game, type_, current_position);
		i++;
	}
	free(line);
}

/**
 *	@brief here's the function for rendering the game map ...
 *	no need to keep track of anything just place the damn sprites
 *	and start collecting them idk use a counter or smth ... !
 *
 *	@todo i have to save these positions
 *	@todo  - wall's positions
 *	@todo  - collectibles positions
 *	@todo  - exit position
 *
 *	@param game game struct !
 */
void	sl_render_map(t_game_data *game)
{
	char	*line;
	int		fd;
	t_vect2	*cpos;

	cpos = (t_vect2 *)malloc(sizeof(t_vect2));
	ft_bzero((void *)cpos, sizeof(t_vect2));
	if (cpos == NULL)
		return ;
	if (!sl_check_mapfile(game->map->mapfp))
	{
		free(cpos);
		return ;
	}
	fd = open(game->map->mapfp, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		render_line(line, cpos, game);
		cpos->x += 48;
		cpos->y = 0;
		line = get_next_line(fd);
	}
	free(cpos);
	close(fd);
}
