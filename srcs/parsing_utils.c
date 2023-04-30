/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:28:06 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/30 16:26:29 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	dont_put_sht_in_the_map(t_map *map, char *tab, int y)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == 'C')
			map->nbr_c++;
		else if (tab[i] == 'P')
		{
			map->p_x = i;
			map->p_y = y;
			map->nbr_p++;
		}
		else if (tab[i] == 'E')
			map->nbr_e++;
		else if (tab[i] != '1' && tab[i] != '0' && tab[i] != 'S')
		{
			ft_printf("Please only use those characters : P, C, E, 1, 0, S\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_outer_wall(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '\n')
			i++;
		else
			return (1);
	}
	return (0);
}

int	shape_map(t_map *map)
{
	int		len;
	int		i;

	i = 0;
	if (check_outer_wall(map->map_tab[0])
		|| check_outer_wall(map->map_tab[map->y - 1]))
		return (1);
	map->x = ft_strlen_pars(map->map_tab[0]);
	while (map->map_tab[i])
	{
		len = ft_strlen_pars(map->map_tab[i]);
		if (len != map->x || map->map_tab[i][0] != '1'
			|| map->map_tab[i][len - 1] != '1')
			return (1);
		if (dont_put_sht_in_the_map(map, map->map_tab[i], i))
			return (1);
		i++;
	}
	return (0);
}
