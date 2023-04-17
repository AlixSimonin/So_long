/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:08:46 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/17 18:47:13 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_map
{
	int		pos_chara_x;
	int		pos_chara_y;
	int		mvt_count;
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
void	game(t_data *var);

// utils //

void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);

#endif