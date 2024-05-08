/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_ones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:45:33 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/08 02:49:31 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

bool	ft_all_ones(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (false);
	while (i < ft_strlen(line) - 1)
	{
		if (line[i] != '1')
			return (false);
		i++;
	}
	return (true);
}
