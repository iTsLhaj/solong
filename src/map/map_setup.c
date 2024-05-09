/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:41:22 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/08 15:22:52 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	sl_map_setup(t_game_data *game, const char *av1)
{
	int	mapcheck_excode;

	mapcheck_excode = -1;
	ft_bzero(game, sizeof(t_game_data));
	sl_load_map(game, av1);
	if (game->error_on_exit)
		return (1);
	sl_set_window_size(game);
	if (game->map == NULL)
	{
		ft_puterror("Invalid Map Provided!\n");
		return (1);
	}
	mapcheck_excode = sl_check_map(game);
	if (!mapcheck_excode)
	{
		sl_game_init_values(game);
		return (0);
	}
	else
	{
		/** @todo check error codes */
		ft_printf("%i\n", mapcheck_excode);
		ft_puterror("Invalid Map Provided!\n");
		free_map(game);
		return (1);
	}

}
