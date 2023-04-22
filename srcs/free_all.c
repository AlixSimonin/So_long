/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:23:36 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/22 17:24:01 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void free_mlx(t_data *var, int nb)
// {
// 	mlx_destroy_window(var->mlx, var->window);
// 	mlx_destroy_display(var->mlx);
// 	free(var->mlx);
// 	exit(nb);
// }

void free_tab(t_map *map, int nb)
{
	int i;
	
	i = 0;
	while(i < map->y)
	{
		free(map->map_tab[i]);
		i++;
	}
	free(map->map_tab);
	if (nb == 1)
		ft_printf("Error\n");
	exit(nb);
}