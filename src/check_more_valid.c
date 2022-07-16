/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_more_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:46:10 by gchernys          #+#    #+#             */
/*   Updated: 2022/07/14 19:45:37 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//check if the map has a valid amount of coins
int	check_coin(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->map[j] != NULL)
	{
		i = 0;
		while (map->map[j][i] != '\0')
		{
			if (map->map[j][i] == 'C')
				map->coin++;
			i++;
		}
		j++;
	}
	if (map->coin == 0)
		return (1);
	else
		return (0);
}

//checks valid amount of players
int	check_player(t_map *map)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	j = 0;
	while (map->map[j] != NULL)
	{
		i = 0;
		while (map->map[j][i] != '\0')
		{
			if (map->map[j][i] == 'P')
				player++;
			i++;
		}
		j++;
	}
	if (player != 1)
		return (1);
	else
		return (0);
}

void	check_ext(char *file, int argc, t_game *game, t_map *map)
{
	char	*c;

	if (argc < 2)
	{
		ft_printf("%s", "Error:\n No File to Use\n");
		free_if_error(map, game, 0);
	}
	c = ft_strnstr(file, ".ber\0", ft_strlen(file));
	if (!c)
	{
		ft_printf("%s", "Error:\n Wrong File Extension\n");
		free_if_error(map, game, 0);
	}
}

void	check_error(char *s, t_map *map, t_game *game)
{
	int	error;

	error = get_map(s, map);
	if (error == -1)
	{
		ft_printf("%s", "Error:\n Wrong Map Configuration/Empty file\n");
		free_if_error(map, game, 0);
	}
	if (error != 0)
	{
		ft_printf("%s", "Error:\n Error while parsing map\n");
		free_if_error(map, game, 1);
	}
}
