/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:00:09 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/08 02:50:01 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	*load_imptr(
	void *mlxptr,
	char *impath,
	int *size_x, int *size_y
)
{
	void	*imptr;

	imptr = mlx_xpm_file_to_image(
			mlxptr, impath,
			size_y, size_x
			);
	if (imptr == NULL)
	{
		free(impath);
		return (NULL);
	}
	free(impath);
	return (imptr);
}

static char	*get_image_path(t_obj_type type)
{
	if (type == INVALID)
		return (NULL);
	if (type == COLLECTIBLE)
		return ("collectible/food.xpm");
	if (type == WALL)
		return ("obstacle/wall.xpm");
	if (type == DOOR_LOCKED)
		return ("exit/locked.xpm");
	if (type == DOOR_UNLOCKED)
		return ("exit/unlocked.xpm");
	if (type == PLAYER)
		return ("player/luffy-left.xpm");
	return (NULL);
}

/**
 * @brief init's a sprite according to the passed type !
 * @param type the object type !
 * @param mlxptr a pinter that is required by mlx function !
 * @return a pointer to a sprite struct !
 * @fixme handle when the image fp <file path> isn't exists !
 */
t_sprite	*ft_mksprite(t_obj_type type, void *mlxptr, char *impath_)
{
	t_sprite	*sprite;
	char		*impath;

	if (impath_)
		impath = impath_;
	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	ft_bzero((void *)sprite, sizeof(t_sprite));
	if (type != NONE)
	{
		impath = get_image_path(type);
		if (impath == NULL)
		{
			free(sprite);
			return (NULL);
		}
	}
	impath = ft_strjoin("textures/", impath);
	sprite->imptr = load_imptr(mlxptr, impath,
			&sprite->size.x, &sprite->size.y);
	if (sprite->imptr == NULL)
	{
		free(sprite);
		return (NULL);
	}
	return (sprite);
}
