/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 07:48:05 by gchernys          #+#    #+#             */
/*   Updated: 2022/07/14 17:52:11 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_error(int x, int y, t_game *game)
{
	int		py;
	int		px;
	char	**map;

	map = game->map->map;
	py = game->map->player->y + y;
	px = game->map->player->x + x;
	if (map[py][px] == '1')
		return (1);
	if (map[py][px] == 'C')
	{
		game->map->coin--;
		map[py][px] = '1';
		return (0);
	}
	if (map[py][px] == 'E' && game->map->coin != 0)
		return (1);
	if (map[py][px] == 'E' && game->map->coin <= 0)
	{	
		game->moves++;
		ft_printf("%d\n", game->moves);
		end_free(game);
	}
	return (0);
}

int	try_move(int x, int y, t_game *game)
{
	char	**s;

	s = game->map->map;
	if (move_error(x, y, game) == 1)
		return (1);
	draw_pic(game, FLOOR, game->map->player->x, game->map->player->y);
	draw_pic(game, FLOOR, game->map->player->x + x, game->map->player->y + y);
	if (game->moves % 2 == 0)
		draw_pic(game, P1, game->map->player->x + x, game->map->player->y + y);
	else
		draw_pic(game, P2, game->map->player->x + x, game->map->player->y + y);
	game->map->player->y += y;
	game->map->player->x += x;
	s[game->map->player->y][game->map->player->x] = 'P';
	game->moves++;
	ft_printf("%d\n", game->moves);
	return (0);
}

int	move(int key, t_game *game)
{
	if (key == 13)
		try_move(0, -1, game);
	if (key == 0)
		try_move(-1, 0, game);
	if (key == 1)
		try_move(0, 1, game);
	if (key == 2)
		try_move(1, 0, game);
	if (key == 53)
		end_free(game);
	return (0);
}
