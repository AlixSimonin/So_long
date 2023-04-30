/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:35:18 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/30 03:36:29 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_exit_open(t_data *var, t_map *map)
{
	if (map->nbr_c == 0)
	{
		mlx_put_image_to_window(var->mlx, var->window, var->exit[0],
			map->e_x * 100, map->e_y * 100);
	}
}

int	move_up(t_data *var, t_map *map)
{
	if (map->nbr_c == 0 && (map->map_tab[map->p_y - 1][map->p_x] == 'E'))
		free_mlx(var, 0);
	if (map->map_tab[map->p_y - 1][map->p_x] == 'S')
	{
		ft_printf("Game Over\n");
		free_mlx(var, 0);
	}
	if ((map->map_tab[map->p_y - 1][map->p_x] != '1')
		&& (map->map_tab[map->p_y - 1][map->p_x] != 'E'))
	{
		mlx_put_image_to_window(var->mlx, var->window, var->floor,
			map->p_x * 100, map->p_y * 100);
		map->p_y -= 1;
		if (map->map_tab[map->p_y][map->p_x] == 'C')
		{
			map->nbr_c--;
			map->map_tab[map->p_y][map->p_x] = '0';
			is_exit_open(var, map);
		}
		mlx_put_image_to_window(var->mlx, var->window, var->player[1],
			map->p_x * 100, map->p_y * 100);
		var->count_move++;
		ft_printf("tot movement = %d\n", var->count_move);
	}
	return (0);
}

int	move_right(t_data *var, t_map *map)
{
	if (map->nbr_c == 0 && (map->map_tab[map->p_y][map->p_x + 1] == 'E'))
		free_mlx(var, 0);
	if (map->map_tab[map->p_y][map->p_x + 1] == 'S')
	{
		ft_printf("Game Over\n");
		free_mlx(var, 0);
	}
	if ((map->map_tab[map->p_y][map->p_x + 1] != '1')
		&& (map->map_tab[map->p_y][map->p_x + 1] != 'E'))
	{
		mlx_put_image_to_window(var->mlx, var->window, var->floor,
			map->p_x * 100, map->p_y * 100);
		map->p_x += 1;
		if (map->map_tab[map->p_y][map->p_x] == 'C')
		{
			map->nbr_c--;
			map->map_tab[map->p_y][map->p_x] = '0';
			is_exit_open(var, map);
		}
		mlx_put_image_to_window(var->mlx, var->window, var->player[2],
			map->p_x * 100, map->p_y * 100);
		var->count_move++;
		ft_printf("tot movement = %d\n", var->count_move);
	}
	return (0);
}

int	move_down(t_data *var, t_map *map)
{
	if (map->nbr_c == 0 && (map->map_tab[map->p_y + 1][map->p_x] == 'E'))
		free_mlx(var, 0);
	if (map->map_tab[map->p_y + 1][map->p_x] == 'S')
	{
		ft_printf("Game Over\n");
		free_mlx(var, 0);
	}
	if ((map->map_tab[map->p_y + 1][map->p_x] != '1')
		&& (map->map_tab[map->p_y + 1][map->p_x] != 'E'))
	{
		mlx_put_image_to_window(var->mlx, var->window, var->floor,
			map->p_x * 100, map->p_y * 100);
		map->p_y += 1;
		if (map->map_tab[map->p_y][map->p_x] == 'C')
		{
			map->nbr_c--;
			map->map_tab[map->p_y][map->p_x] = '0';
			is_exit_open(var, map);
		}
		mlx_put_image_to_window(var->mlx, var->window, var->player[3],
			map->p_x * 100, map->p_y * 100);
		var->count_move++;
		ft_printf("tot movement = %d\n", var->count_move);
	}
	return (0);
}

int	move_left(t_data *var, t_map *map)
{
	if (map->nbr_c == 0 && (map->map_tab[map->p_y][map->p_x - 1] == 'E'))
		free_mlx(var, 0);
	if (map->map_tab[map->p_y][map->p_x - 1] == 'S')
	{
		ft_printf("Game Over\n");
		free_mlx(var, 0);
	}
	if ((map->map_tab[map->p_y][map->p_x - 1] != '1')
		&& (map->map_tab[map->p_y][map->p_x - 1] != 'E'))
	{
		mlx_put_image_to_window(var->mlx, var->window, var->floor,
			map->p_x * 100, map->p_y * 100);
		map->p_x -= 1;
		if (map->map_tab[map->p_y][map->p_x] == 'C')
		{
			map->nbr_c--;
			map->map_tab[map->p_y][map->p_x] = '0';
			is_exit_open(var, map);
		}
		mlx_put_image_to_window(var->mlx, var->window, var->player[4],
			map->p_x * 100, map->p_y * 100);
		var->count_move++;
		ft_printf("tot movement = %d\n", var->count_move);
	}
	return (0);
}
