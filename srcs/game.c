/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:41:23 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/17 18:48:15 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_game(t_data *var)
{
	mlx_destroy_window(var->mlx, var->window);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
}

int	key_hook(KeySym keycode, t_data *var)
{
	int	pos_x;
	int	pos_y;

	pos_x = var->character->pos_x; // T NUL
	pos_y = var->character->pos_y; // T NUL 
	if (keycode == XK_Escape)
		return (mlx_loop_end(var->mlx));
	else if (keycode == XK_Up || keycode == XK_W || keycode == XK_w)
		return (move_up(var, pos_x, pos_y));
	else if (keycode == XK_Down || keycode == XK_S || keycode == XK_s)
		return (move_down(var, pos_x, pos_y));
	else if (keycode == XK_Left || keycode == XK_A || keycode == XK_a)
		return (move_left(var, pos_x, pos_y));
	else if (keycode == XK_Right || keycode == XK_D || keycode == XK_d)
		return (move_right(var, pos_x, pos_y));
	else
		return (1);
}

void	game(t_data *var)
{
	var->mlx = mlx_init();
	if (var->mlx == NULL)
		return ;
	var->window = mlx_new_window(var->mlx, 1000, 500, "So_long");
	if (var->window == NULL)
	{
		free(var->window);
		return ;
	}
	mlx_hook(var->window, KeyPress, KeyPressMask, key_hook, var);
	mlx_hook(var->window, KeyPress, KeyPressMask, key_hook, var);
	var->image = mlx_xpm_file_to_image(var->mlx, "assets/ground.xpm", &var->img_x, &var->img_y);

	// var->img2 = mlx_xpm_file_to_image(var -> mlx, "assets/chest.xpm", &var->img_x, &var->img_y);
	// if (!var->image || !var->img2)
	// {
		//freeall()
		// TODO : check destroy image
	// }
	mlx_put_image_to_window(var->mlx, var->window, var->image, 0, 0);
	mlx_put_image_to_window(var->mlx, var->window, var->image, 100, 0);
	mlx_put_image_to_window(var->mlx, var->window, var->image, 200, 0);
	mlx_put_image_to_window(var->mlx, var->window, var->image, 300, 0);
	mlx_put_image_to_window(var->mlx, var->window, var->image, 0, 100);
	mlx_put_image_to_window(var->mlx, var->window, var->image, 0, 200);
	mlx_put_image_to_window(var->mlx, var->window, var->image, 0, 300);
	mlx_put_image_to_window(var->mlx, var->window, var->image, 0, 400);
	// mlx_destroy_window(var->mlx, var->window);
	// mlx_destroy_display(var->mlx);
	mlx_loop(var->mlx);
	free(var->mlx);
}