/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:41:22 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/08 02:50:01 by hmouhib          ###   ########.fr       */
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
