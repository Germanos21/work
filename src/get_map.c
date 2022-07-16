/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:15:47 by gchernys          #+#    #+#             */
/*   Updated: 2022/07/16 19:00:37 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//get the map from the file
int	get_map(char *file, t_map *map)
{
	int		fd_error;
	char	*temp;
	char	*str;

	fd_error = open(file, O_RDONLY);
	str = NULL;
	temp = get_next_line(fd_error);
	if (!temp)
	{
		ft_printf("%s", "Error:\n Invalid Action");
		exit(0);
	}
	while (temp != NULL)
	{
		if (temp != NULL && temp[0] == '\n')
			return (-1);
		str = ft_strjoin_gnl(str, temp);
		temp = get_next_line(fd_error);
	}
	free(temp);
	fd_error = call_check(str, map);
	return (fd_error);
}

int	check_map_by_lines(const char *str, t_map *map)
{
	int	j;

	j = 0;
	map->map = ft_split(str, '\n');
	map->wide = ft_strlen(map->map[0]);
	while (map->map[j] != NULL)
	{
		if (ft_strlen(map->map[j]) != map->wide)
			return (1);
		j++;
	}
	map->high = j;
	return (0);
}

int	call_check(char *str, t_map *map)
{
	int	error;

	if (str == NULL)
		return (0);
	error = check_map_by_lines(str, map);
	if (error == 0)
	{
		error += check_player(map);
		error += check_top_bot(map);
		error += check_side(map);
		error += check_leave(map);
		error += check_coin(map);
		error += check_symbol(map);
	}
	return (error);
}
