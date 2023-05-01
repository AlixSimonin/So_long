/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_in_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:44:21 by asimonin          #+#    #+#             */
/*   Updated: 2023/05/01 13:32:11 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	lolice(t_data *var, int mvt)
{
	char	*car;

	mlx_put_image_to_window(var->mlx, var->window, var->wall, 0, 0);
	car = printf_itoa(mvt);
	if (car == NULL)
		free_mlx(var, 1);
	mlx_string_put(var->mlx, var->window, 25, 25, 0xB533FF, car);
	ft_printf("tot movement = %d\n", mvt);
	free(car);
}

void	init_player(t_data *var)
{
	var->player[0] = mlx_xpm_file_to_image(var->mlx,
			"assets/0_player.xpm", &var->img_x, &var->img_y);
	var->player[1] = mlx_xpm_file_to_image(var->mlx,
			"assets/1_player.xpm", &var->img_x, &var->img_y);
	var->player[2] = mlx_xpm_file_to_image(var->mlx,
			"assets/2_player.xpm", &var->img_x, &var->img_y);
	var->player[3] = mlx_xpm_file_to_image(var->mlx,
			"assets/3_player.xpm", &var->img_x, &var->img_y);
	var->player[4] = mlx_xpm_file_to_image(var->mlx,
			"assets/4_player.xpm", &var->img_x, &var->img_y);
	if (!var->player[0] || !var->player[1] || !var->player[2]
		|| !var->player[3] || !var->player[4]
		|| !var->wall || !var->floor || !var->chest
		|| !var->exit[1] || !var->exit[0] || !var->eye)
		free_mlx(var, 1);
}

void	init_img(t_data *var)
{
	var->floor = mlx_xpm_file_to_image(var->mlx,
			"assets/floor.xpm", &var->img_x, &var->img_y);
	var->wall = mlx_xpm_file_to_image(var->mlx,
			"assets/wall.xpm", &var->img_x, &var->img_y);
	var->chest = mlx_xpm_file_to_image(var->mlx,
			"assets/chest.xpm", &var->img_x, &var->img_y);
	var->exit[1] = mlx_xpm_file_to_image(var->mlx,
			"assets/exit1.xpm", &var->img_x, &var->img_y);
	var->exit[0] = mlx_xpm_file_to_image(var->mlx,
			"assets/exit.xpm", &var->img_x, &var->img_y);
	var->eye = mlx_xpm_file_to_image(var->mlx,
			"assets/side_eye.xpm", &var->img_x, &var->img_y);
	init_player(var);
}

void	background_two(t_map *map, t_data *var, int x, int y)
{
	if (map->map_tab[y][x] == 'P')
	{
		mlx_put_image_to_window(var->mlx,
			var->window, var->player[0], x * 100, y * 100);
		map->p_x = x;
		map->p_y = y;
	}
	else if (map->map_tab[y][x] == 'E')
	{
		mlx_put_image_to_window(var->mlx,
			var->window, var->exit[1], x * 100, y * 100);
		map->e_x = x;
		map->e_y = y;
	}
	else if (map->map_tab[y][x] == 'S')
		mlx_put_image_to_window(var->mlx,
			var->window, var->eye, x * 100, y * 100);
}

void	background(t_map *map, t_data *var)
{
	int	x;
	int	y;

	y = 0;
	init_img(var);
	while (map->map_tab[y])
	{
		x = 0;
		while (map->map_tab[y][x])
		{
			if (map->map_tab[y][x] == '1')
				mlx_put_image_to_window(var->mlx,
					var->window, var->wall, x * 100, y * 100);
			else if (map->map_tab[y][x] == '0')
				mlx_put_image_to_window(var->mlx,
					var->window, var->floor, x * 100, y * 100);
			else if (map->map_tab[y][x] == 'C')
				mlx_put_image_to_window(var->mlx,
					var->window, var->chest, x * 100, y * 100);
			else
				background_two(map, var, x, y);
			x++;
		}
		y++;
	}
}
