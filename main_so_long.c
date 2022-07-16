/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:36:59 by gchernys          #+#    #+#             */
/*   Updated: 2022/07/16 20:02:29 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//main function of so_long
int	main(int argc, char **argv)
{
	t_game	*game;
	t_map	*map;

	game = malloc(sizeof(t_game));
	map = malloc(sizeof(t_map));
	build_images(map, game);
	check_ext(argv[1], argc, game, map);
	check_error(argv[1], map, game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	draw_map(map, game);
	mlx_hook(game->mlx_window, 2, (1L << 0), move, game);
	mlx_hook(game->mlx_window, 17, (1L << 17), end_free, game);
	mlx_loop(game->mlx);
	return (0);
}
