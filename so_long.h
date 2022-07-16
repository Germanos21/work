/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:46:41 by gchernys          #+#    #+#             */
/*   Updated: 2022/07/16 16:52:02 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define WALL "./sprites/wall.xpm"
# define FLOOR "./sprites/floor.xpm"
# define P1 "./sprites/player.xpm"
# define LEAVE "./sprites/leave.xpm"
# define COIN "./sprites/coin.xpm"
# define P2 "./sprites/playertwo.xpm"

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_map
{
	char	**map;
	int		wide;
	int		high;
	int		coin;
	t_pos	*player;
}		t_map;

typedef struct s_game
{
	t_map	*map;
	int		moves;
	void	*mlx;
	void	*mlx_window;
	void	*image;
}		t_game;

int		check_coin(t_map *map);
int		check_player(t_map *map);
void	check_ext(char *file, int argc, t_game *game, t_map *map);
void	check_error(char *s, t_map *map, t_game *game);
int		check_symbol(t_map *map);
int		check_top_bot(t_map *map);
int		check_side(t_map *map);
int		check_leave(t_map *map);
void	free_str(char **str);
void	max_free(t_game *game, t_map *map);
void	free_if_error(t_map *map, t_game *game, int er);
int		end_free(t_game *game);
void	player_pos(t_map *map);
void	build_images(t_map *map, t_game *game);
void	make_window(t_game *game, t_map *map);
int		main(int argc, char **argv);
void	pick_pic(t_game *game, char c, int i, int j);
void	draw_pic(t_game *game, char *path, int i, int j);
void	draw_map(t_map *map, t_game *game);
int		get_map(char *file, t_map *map);
int		call_check(char *str, t_map *map);
int		check_map_by_lines(const char *str, t_map *map);
char	*get_filename_ext(const char *file);
int		move_error(int x, int y, t_game *game);
int		try_move(int x, int y, t_game *game);
int		move(int key, t_game *game);

#endif