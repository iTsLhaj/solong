/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headache.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:19:13 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/16 17:32:12 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	sl_check_mapfext(char *mapfp, void *map)
{
	int		i;
	int		j;
	char	*fext;

	fext = ".ber";
	i = 0;
	while (mapfp[i + 1])
		i++;
	j = 3;
	while (i > 0 && j > 0)
	{
		if (mapfp[i] != fext[j])
		{
			ft_puterror("Invalid Map Provided!\n");
			free(map);
			return (1);
		}
		i--;
		j--;
	}
	return (0);
}
