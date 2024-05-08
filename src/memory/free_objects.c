/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:18:20 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/08 02:50:01 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	ft_delone(t_objects *current_object, void *mlxptr)
{
	if (!current_object)
		return ;
	else
	{
		mlx_destroy_image(mlxptr, current_object->sprite->imptr);
		free(current_object->sprite);
		free(current_object);
	}
}

void	free_objects(t_objects **head_object, void *mlxptr)
{
	t_objects	*tmp;

	if (!head_object || !*head_object)
		return ;
	while (*head_object)
	{
		tmp = (*head_object)->next;
		ft_delone(*head_object, mlxptr);
		*head_object = tmp;
	}
}
