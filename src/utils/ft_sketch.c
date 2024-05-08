/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sketch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:02:15 by meow              #+#    #+#             */
/*   Updated: 2024/05/04 19:03:15 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/** @bref all it des is drawing a certain area in the game with a color ! */
void	ft_fill_area(
	t_vect2 point,
	t_vect2 epoint,
	t_game_data *game,
	int color
)
{
	int	x;
	int	y;

	x = point.x;
	while (x < point.x + epoint.x)
	{
		y = point.y;
		while (y < point.y + epoint.y)
		{
			mlx_pixel_put(
				game->mlxptr,
				game->winptr,
				y, x, color
				);
			y++;
		}
		x++;
	}
}

void	fill_background(t_game_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->map_bounds->y * 48)
	{
		y = 0;
		while (y < game->map->map_bounds->x * 48)
		{
			mlx_pixel_put(
				game->mlxptr,
				game->winptr,
				x, y,
				0xC2B280);
			y++;
		}
		x++;
	}
}
