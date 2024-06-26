/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_to_side.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:59:55 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/08 02:50:01 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <X11/keysym.h>

t_side	ft_key2side(int xkey)
{
	if (xkey == XK_w)
		return (UP);
	else if (xkey == XK_a)
		return (LEFT);
	else if (xkey == XK_s)
		return (DOWN);
	else if (xkey == XK_d)
		return (RIGHT);
	else
		return (UNLISTED);
}
