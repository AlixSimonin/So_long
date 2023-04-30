/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:32:54 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/30 01:31:57 by asimonin         ###   ########.fr       */
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
			if (map[i][j] != 'C')
				j++;
			else
				return (ft_free_tab(map), 1);
		}
		i++;
	}
	return (ft_free_tab(map), 0);
}

void	floodfill(char **map, int x, int y, t_map *maps)
{
	map[y][x] = 'M';
	if (y - 1 >= 0 && !(map[y - 1][x] == 'E' && map[y - 1][x] == '1'
		&& map[y - 1][x] == 'M' && map[y - 1][x] == 'P'))
		floodfill(map, x, y--, maps);
	if (y + 1 < maps->y && !(map[y + 1][x] == 'E' && map[y + 1][x] == '1'
		&& map[y + 1][x] == 'M' && map[y + 1][x] == 'P'))
		floodfill(map, x, y++, maps);
	if (x + 1 < maps->x && !(map[y][x + 1] == 'E' && map[y][x + 1] == '1'
		&& map[y][x + 1] == 'M' && map[y][x + 1] == 'P'))
		floodfill(map, x++, y, maps);
	if (x - 1 >= 0 && !(map[y][x - 1] == 'E' && map[y][x - 1] == '1'
		&& map[y][x - 1] == 'M' && map[y][x - 1] == 'P'))
		floodfill(map, x--, y, maps);
	// if (y - 1 >= 0 && (map[y - 1][x] != 'E' || map[y - 1][x] != '1'
	// 	|| map[y - 1][x] != 'M' || map[y - 1][x] != 'P'))
	// 	floodfill(map, x, y--, maps);
	// if (y + 1 < maps->y && (map[y + 1][x] != 'E' || map[y + 1][x] != '1'
	// 	|| map[y + 1][x] != 'M' || map[y + 1][x] != 'P'))
	// 	floodfill(map, x, y++, maps);
	// if (x + 1 < maps->x && (map[y][x + 1] != 'E' || map[y][x + 1] != '1'
	// 	|| map[y][x + 1] != 'M' || map[y][x + 1] != 'P'))
	// 	floodfill(map, x++, y, maps);
	// if (x - 1 >= 0 && (map[y][x - 1] != 'E' || map[y][x - 1] != '1'
	// 	|| map[y][x - 1] != 'M' || map[y][x - 1] != 'P'))
	// 	floodfill(map, x--, y, maps);
}
