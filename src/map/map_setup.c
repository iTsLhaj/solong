/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:41:22 by meow              #+#    #+#             */
/*   Updated: 2024/05/07 02:22:43 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	sl_map_setup(t_game_data *game, const char *av1)
{
	ft_bzero(game, sizeof(t_game_data));
	sl_load_map(game, av1);
	sl_set_window_size(game);
	sl_game_init_values(game);
	if (game->map == NULL)
	{
		ft_puterror("Invalid Map Provided!\n");
		return (1);
	}
	if (sl_check_map(game))
	{
		ft_puterror("Invalid Map Provided!\n");
		free_map(game);
		return (1);
	}
	return (0);
}
