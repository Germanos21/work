/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:11:34 by gchernys          #+#    #+#             */
/*   Updated: 2022/07/15 15:53:58 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	pick_pic(t_game *game, char c, int x, int y)
{
	if (c == '1')
		draw_pic(game, WALL, x, y);
	if (c == '0')
		draw_pic(game, FLOOR, x, y);
	if (c == 'P')
	{
		draw_pic(game, FLOOR, x, y);
		draw_pic(game, P2, x, y);
	}
	if (c == 'E')
		draw_pic(game, LEAVE, x, y);
	if (c == 'C')
	{
		draw_pic(game, FLOOR, x, y);
		draw_pic(game, COIN, x, y);
	}
}

void	draw_pic(t_game *game, char *path, int i, int j)
{
	int	size;

	size = 64;
	i = i * size;
	j = j * size;
	game->image = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->image, i, j);
	mlx_destroy_image(game->mlx, game->image);
}

void	draw_map(t_map *map, t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	make_window(game, map);
	while (map->map[j] != NULL)
	{
		i = 0;
		while (map->map[j][i] != '\0')
		{
			pick_pic(game, map->map[j][i], i, j);
			i++;
		}
		j++;
	}
	player_pos(map);
	game->map = map;
}
