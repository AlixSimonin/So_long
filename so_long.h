/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:08:46 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/30 17:09:37 by asimonin         ###   ########.fr       */
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
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_map
{
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		mvt_count;
	int		nbr_p;
	int		nbr_e;
	int		nbr_c;
	char	**map_tab;
	char	**dup;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*wall;
	void	*floor;
	void	*player[5];
	void	*chest;
	void	*exit[2];
	void	*eye;
	int		img_x;
	int		img_y;
	t_map	*map;
	size_t	count_move;
}	t_data;

// sources //

int		main(int ac, char **av);
int		check_arg(char *av);
int		check_map(char *ber, t_map *map);
int		shape_map(t_map *map);
int		check_outer_wall(char *str);
int		dont_put_sht_in_the_map(t_map *map, char *tab, int y);
int		move_up(t_data *var, t_map *map);
int		move_right(t_data *var, t_map *map);
int		move_left(t_data *var, t_map *map);
int		move_down(t_data *var, t_map *map);

size_t	ft_strlen_pars(char *s);

void	fill_map(t_map *map, int fd);
void	game(t_data *var, t_map *map);
void	free_tab(t_map *map, int nb);
void	free_mlx(t_data *var, int nb);
void	background(t_map *map, t_data *var);
void	init_img(t_data *var);
void	ft_free_tab(char **tab);
void	lolice(t_data *var, int mvt);
void	floodfill(char **map, int x, int y, t_map *maps);

char	*ft_strjoin_pars(char *s1, char *s2);
char	**duplicate(char **map, int size);

int		check_if_c(char **map);

#endif