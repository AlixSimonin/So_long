/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:37:22 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/30 03:20:24 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init(t_map *map, t_data *var)
{
	map->nbr_c = 0;
	map->nbr_e = 0;
	map->nbr_p = 0;
	map->x = 0;
	map->y = 0;
	var->img_x = 100;
	var->img_y = 100;
	var->count_move = 0;
}

int	main(int ac, char **av)
{
	t_data	var;
	t_map	map;

	ft_memset(&var, 0, sizeof(var));
	ft_memset(&map, 0, sizeof(map));
	init(&map, &var);
	if (ac != 2 || check_arg(av[1]) == 1)
		return (write(1, "Invalid argument, please input a map.ber\n", 41), 1);
	if (check_map(av[1], &map))
		free_tab(&map, 1);
	//floodfill(map.dup, map.pos_chara_x, map.pos_chara_y, &map);
	// if (check_if_c(map.dup) == 0)
	game(&var, &map);
	// if (floodfill(map.dup, map.pos_chara_x, map.pos_chara_y, &map))
	// 	game(&var, &map);
	free_tab(&map, 0);
	return (0);
}
