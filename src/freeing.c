/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 23:09:30 by gchernys          #+#    #+#             */
/*   Updated: 2022/07/14 17:52:58 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_str(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	max_free(t_game *game, t_map *map)
{
	free_str(map->map);
	free(map->player);
	free(map);
	free(game);
}

void	free_if_error(t_map *map, t_game *game, int er)
{
	if (er == 1)
	{
		free_str(map->map);
		free(map->player);
	}
	free(map);
	free(game);
	exit(0);
}

int	end_free(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_window);
	mlx_destroy_window(game->mlx, game->mlx_window);
	max_free(game, game->map);
	ft_printf("%s", "Game Ended");
	exit(0);
}
