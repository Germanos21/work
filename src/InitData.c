/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitData.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 23:01:34 by gchernys          #+#    #+#             */
/*   Updated: 2022/07/14 17:28:05 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
//get player position
void	player_pos(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x] != '\0')
		{
			if (map->map[y][x] == 'P')
			{
				map->player->x = x;
				map->player->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	build_images(t_map *map, t_game *game)
{
	map->player = malloc(sizeof(t_game));
	map->coin = 0;
	game->moves = 0;
}

void	make_window(t_game *game, t_map *map)
{
	int	wide;
	int	high;
	int	size;

	size = 64;
	wide = map->wide * size;
	high = map->high * size;
	game->mlx_window = mlx_new_window(game->mlx, wide, high, "so_long");
}
