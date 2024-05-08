/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_ones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meow <meow@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:45:33 by meow              #+#    #+#             */
/*   Updated: 2024/05/04 18:45:33 by meow             ###   ########.fr       */
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
