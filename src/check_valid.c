/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:45:40 by gchernys          #+#    #+#             */
/*   Updated: 2022/07/16 16:51:44 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
//check that the map is only composed of 5 symbols, P, C, E, 0, 1
int	check_symbol(t_map *map)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	while (map->map[j] != NULL)
	{
		i = 0;
		while (map->map[j][i] != '\0')
		{
			c = map->map[j][i];
			if (c != 'P' && c != 'E' && c != 'C' && c != '1' && c != '0')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

// check that the top and bottom of the map is made up of ones only
int	check_top_bot(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->wide)
	{
		if (map->map[0][i] != '1')
			return (1);
		if (map->map[map->high - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

//check that the map is closed off with '1' from the sides
int	check_side(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[j] != NULL)
	{
		if ((map->map[j][i] != '1') || (map->map[j][map->wide - 1]) != '1')
			return (1);
		j++;
	}
	return (0);
}

//check valid amount of leaves
int	check_leave(t_map *map)
{
	int	i;
	int	j;
	int	leave;

	leave = 0;
	j = 0;
	while (map->map[j] != NULL)
	{
		i = 0;
		while (map->map[j][i] != '\0')
		{
			if (map->map[j][i] == 'E')
				leave++;
			i++;
		}
		j++;
	}
	if (leave == 0)
		return (1);
	else
		return (0);
}
