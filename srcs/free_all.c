/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:23:36 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/30 16:31:38 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_assets(t_data *var)
{
	mlx_destroy_image(var->mlx, var->chest);
	mlx_destroy_image(var->mlx, var->wall);
	mlx_destroy_image(var->mlx, var->floor);
	mlx_destroy_image(var->mlx, var->exit[0]);
	mlx_destroy_image(var->mlx, var->exit[1]);
	mlx_destroy_image(var->mlx, var->player[0]);
	mlx_destroy_image(var->mlx, var->player[1]);
	mlx_destroy_image(var->mlx, var->player[2]);
	mlx_destroy_image(var->mlx, var->player[3]);
	mlx_destroy_image(var->mlx, var->player[4]);
	mlx_destroy_image(var->mlx, var->eye);
}

void	free_mlx(t_data *var, int nb)
{
	free_assets(var);
	mlx_destroy_window(var->mlx, var->window);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	free_tab(var->map, nb);
	exit(0);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_tab(t_map *map, int nb)
{
	int	i;

	i = 0;
	if (!map -> map_tab)
	{
		ft_printf("Error\n");
		exit(nb);
	}
	while (i < map->y)
	{
		free(map->map_tab[i]);
		free(map->dup[i]);
		i++;
	}
	free(map->map_tab);
	free(map->dup);
	if (nb == 1)
	{
		ft_printf("Error\n");
		exit(nb);
	}
}
