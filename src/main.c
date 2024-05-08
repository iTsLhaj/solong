/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:23:33 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/07 02:10:29 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <X11/keysym.h>

static int	exit_game(t_game_data *game)
{
	sl_free_all_game_memory(game);
	mlx_destroy_window(game->mlxptr, game->winptr);
	mlx_destroy_display(game->mlxptr);
	free(game->mlxptr);
	exit(0);
	return (0);
}

/**
 *	@brief a key hook function for mlx
 *	@todo handle <esc> key instead of printing "another key pressed" !
 */
static int	key_hook(int keycode, t_game_data *game_vars)
{
	t_vect2	*new_p;

	new_p = NULL;
	if (
		keycode == XK_w
		|| keycode == XK_a
		|| keycode == XK_s
		|| keycode == XK_d
	)
	{
		if (keycode == XK_a)
			game_vars->player_direction = 'l';
		else if (keycode == XK_d)
			game_vars->player_direction = 'r';
		on_keyclick_rituals(keycode, game_vars, new_p);
	}
	else if (keycode == XK_Escape || keycode == XK_q)
		mlx_loop_end(game_vars->mlxptr);
	sl_end_game_checking(game_vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game_data	game;

	if (argc != 2)
	{
		ft_printf("usage: %s <map_file>.ber\n", argv[0]);
		return (1);
	}
	if (sl_map_setup(&game, argv[1]))
		return (1);
	if (game.error_on_exit)
		return (1);
	sl_render_map(&game);
	if (game.error_on_exit)
		mlx_loop_end(game.mlxptr);
	mlx_key_hook(game.winptr, &key_hook, &game);
	mlx_hook(game.winptr, 17, 0, &exit_game, &game);
	mlx_loop(game.mlxptr);
	sl_free_all_game_memory(&game);
	mlx_destroy_window(game.mlxptr, game.winptr);
	mlx_destroy_display(game.mlxptr);
	if (game.status)
		ft_printf("Congratulations .. You Won!\n");
	free(game.mlxptr);
	if (game.error_on_exit)
		return (1);
}
