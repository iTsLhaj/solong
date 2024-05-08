/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:32:24 by meow              #+#    #+#             */
/*   Updated: 2024/05/04 18:32:35 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	to_up(t_vect2 *curp, t_vect2 *nextp)
{
	nextp->y = curp->y;
	nextp->x = curp->x - 48;
}

static void	to_left(t_vect2 *curp, t_vect2 *nextp)
{
	nextp->y = curp->y - 48;
	nextp->x = curp->x;
}

static void	to_down(t_vect2 *curp, t_vect2 *nextp)
{
	nextp->y = curp->y;
	nextp->x = curp->x + 48;
}

static void	to_right(t_vect2 *curp, t_vect2 *nextp)
{
	nextp->y = curp->y + 48;
	nextp->x = curp->x;
}

void	update_sidep(t_vect2 *curp, t_vect2 *nextp, t_side s)
{
	if (s == UP)
		to_up(curp, nextp);
	else if (s == LEFT)
		to_left(curp, nextp);
	else if (s == DOWN)
		to_down(curp, nextp);
	else if (s == RIGHT)
		to_right(curp, nextp);
	else
	{
		nextp->y = curp->y;
		nextp->x = curp->x;
	}
}
