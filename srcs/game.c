/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:41:23 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/30 18:25:26 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	escape(t_data *var)
{
	free_mlx(var, 0);
	return (0);
}

int	key_hook(KeySym keycode, t_data *var)
{
	if (keycode == XK_Escape)
		return (escape(var));
	else if (keycode == XK_Up || keycode == XK_W || keycode == XK_w)
		return (move_up(var, var->map));
	else if (keycode == XK_Down || keycode == XK_S || keycode == XK_s)
		return (move_down(var, var->map));
	else if (keycode == XK_Left || keycode == XK_A || keycode == XK_a)
		return (move_left(var, var->map));
	else if (keycode == XK_Right || keycode == XK_D || keycode == XK_d)
		return (move_right(var, var->map));
	else
		return (1);
}

void	game(t_data *var, t_map *map)
{
	var->map = map;
	var->mlx = mlx_init();
	if (var->mlx == NULL)
		return (free_tab(map, 1));
	var->window = mlx_new_window(var->mlx,
			(map->x) * 100, (map->y - 1) * 100, "So_long");
	if (var->window == NULL)
		return (free(var->window));
	background(map, var);
	mlx_hook(var->window, DestroyNotify, KeyPressMask, escape, var);
	mlx_hook(var->window, KeyPress, KeyPressMask, key_hook, var);
	mlx_loop(var->mlx);
	free_mlx(var, 0);
}
