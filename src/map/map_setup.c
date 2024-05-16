/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:41:22 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/16 17:24:37 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	sl_map_setup(t_game_data *game, const char *av1)
{
	ft_bzero(game, sizeof(t_game_data));
	if (!sl_check_mapfile(av1))
	{
		ft_puterror("Invalid Map File!\n");
		return (1);
	}
	sl_load_map(game, av1);
	if (game->error_on_exit)
		return (1);
	sl_set_window_size(game);
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
	sl_game_init_values(game);
	return (0);
}
