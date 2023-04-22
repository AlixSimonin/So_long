/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:10:22 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/22 18:34:03 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	dont_put_sht_in_the_map(t_map *map, char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == 'C')
			map->nbr_c++;
		else if (tab[i] == 'P')
			map->nbr_p++;
		else if (tab[i] == 'E')
			map->nbr_e++;
		else if (tab[i] != '1' && tab[i] != '0')
		{
			ft_printf("Please only use those characters : P, C, E, 1, 0\n");
			return (1);
		}
		i++;
	}
	return (0);
	
}
void	fill_map(t_map *map, int fd)
{
	int	i;
	char	*str;

	i = 0;
	map->map_tab = malloc((map->y + 1) * sizeof(char *));
	
	if (!map->map_tab)
		free_tab(map, 1);
	while (i < map->y)
	{
		map->map_tab[i]= malloc(sizeof(char) * map->x);
		if (!map->map_tab[i])
			free_tab(map, 1);
		str = get_next_line(fd, 0);
		ft_strlcpy(map->map_tab[i], str, map->x);
		free(str);
		if (dont_put_sht_in_the_map(map, map->map_tab[i]))
			free_tab(map, 1);
		i++;
	}
}

int	check_outer_wall(char *str)
{
	int i;

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

int shape_map(int fd, t_map *map)
{
	int	len;
	char	*str;
	
	str = get_next_line(fd, 0);
	if (!str)
		return(1);
	map->x = ft_strlen(str);
	if (check_outer_wall(str))
		return (1);
	while (str)
	{
		len = ft_strlen(str);
		if (len != map->x || str[0] != '1' || str[len - 2] != '1')
			break;
		free(str);
		str = get_next_line(fd, 0);
		map->y++;
	}
	if ((map->x < 5 && map-> y < 5) || check_outer_wall(str))
		return (1);
	if (len + 1 == map->x)
		map->y++;
	if (len != map->x)
	{
		free(str);
		return (1);
	}
	return (0);
}

int check_map(char *ber, t_map *map)
{
	int	fd;

	fd = open(ber, O_RDONLY);
	if (shape_map(fd, map))
	{
		ft_printf("Error\n");
		exit(1);
	}
		
	fd = open(ber, O_RDONLY);
	fill_map(map, fd);
	if (map->nbr_c < 1)
	{
		ft_printf("Map need to have at least one collectible\n");
		return (1);
	}
	if (map->nbr_p != 1)
	{
		ft_printf("Map need to have one character\n");
		return (1);
	}
	if (map->nbr_e != 1)
	{
		ft_printf("Map need to have one exit\n");
		return (1);
	}
	return (0);
}