/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:08:46 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/22 17:26:23 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
//# include "minilibx-linux/mlx.h"
//# include "minilibx-linux/mlx_int.h"

typedef struct s_map
{
	int		x;
	int		y;
	int		pos_chara_x;
	int		pos_chara_y;
	int		mvt_count;
	int		nbr_p;
	int		nbr_e;
	int		nbr_c;
	char	**map_tab;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*image;
	int		img_x;
	int		img_y;
}	t_data;

// sources //

int		main(int ac, char **av);
int		check_arg(char *av);
int 	check_map(char *ber, t_map *map);
int		shape_map(int fd, t_map *map);
int		check_outer_wall(char *str);
int		dont_put_sht_in_the_map(t_map *map, char *tab);
void	fill_map(t_map *map, int fd);
void	game(t_data *var);
void	free_tab(t_map *map, int nb);
void	free_mlx(t_data *var, int nb);

#endif