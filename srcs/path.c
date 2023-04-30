/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:32:54 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/30 20:54:41 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_if_c(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'C' && map[i][j] != 'E')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

void	is_exit(char **map, int x, int y, t_map *maps)
{
	if (y - 1 >= 0 && map[y - 1][x] == 'E')
		map[y - 1][x] = 'M';
	else if (y + 1 < maps->y && map[y + 1][x] == 'E')
		map[y + 1][x] = 'M';
	else if (x - 1 >= 0 && map[y][x - 1] == 'E')
		map[y][x - 1] = 'M';
	else if (y + 1 < maps->x && map[y][x - 1] == 'E')
		map[y][x + 1] = 'M';
}

void	floodfill(char **map, int x, int y, t_map *maps)
{
	map[y][x] = 'M';
	is_exit(map, x, y, maps);
	if (y - 1 >= 0 && (map[y - 1][x] != '1'
		&& map[y - 1][x] != 'M' && map[y - 1][x] != 'S'))
		floodfill(map, x, (y - 1), maps);
	if (y + 1 < maps->y && (map[y + 1][x] != '1'
		&& map[y + 1][x] != 'M' && map[y + 1][x] != 'S'))
		floodfill(map, x, (y + 1), maps);
	if (x + 1 < maps->x && (map[y][x + 1] != '1'
		&& map[y][x + 1] != 'M' && map[y][x + 1] != 'S'))
		floodfill(map, (x + 1), y, maps);
	if (x - 1 >= 0 && (map[y][x - 1] != '1'
		&& map[y][x - 1] != 'M' && map[y][x - 1] != 'S'))
		floodfill(map, (x - 1), y, maps);
}
