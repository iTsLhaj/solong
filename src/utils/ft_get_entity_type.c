/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_entity_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:59:32 by meow              #+#    #+#             */
/*   Updated: 2024/05/04 18:59:48 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 *	@brief return's the t_obj_type according to the passed char from the map !
 *	@param c character
 *	@return the type INVALID if invalid UNLISTED if not included in the types !
 */
t_obj_type	ft_get_entity_type(char c)
{
	if (c == 'C')
		return (COLLECTIBLE);
	else if (c == 'E')
		return (DOOR_LOCKED);
	else if (c == '1')
		return (WALL);
	else if (c == 'P')
		return (PLAYER);
	else if (c == '0')
		return (EMPTY);
	else
		return (INVALID);
}
