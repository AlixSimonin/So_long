/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:10:22 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/30 17:51:08 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_len(t_map *map, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] == '\n')
		len -= 1;
	if (len != map->x || str[0] != '1' || str[len - 1] != '1')
		return (1);
	return (0);
}

void	fill_map_too(char *lime, int fd, int i)
{
	get_next_line(fd, 1);
	if (i == 1)
	{
		close(fd);
		free(lime);
		ft_printf("Error\nAll lines doesnt have the same lenght\n");
		exit(1);
	}
}

char	*map_in_line(t_map *map, int fd)
{
	char	*line;
	char	*stock;
	int		i;

	i = 0;
	line = ft_calloc(1, 1);
	if (!line)
		return (NULL);
	stock = get_next_line(fd, 0);
	map->x = ft_strlen_pars(stock);
	if (stock[map->x -1] == '\n')
		map->x -= 1;
	while (1)
	{
		if (!stock)
			break ;
		line = ft_strjoin_pars(line, stock);
		if (check_len(map, stock))
			i = 1;
		free(stock);
		map->y++;
		stock = get_next_line(fd, 0);
	}
	fill_map_too(line, fd, i);
	return (line);
}

void	fill_map(t_map *map, int fd)
{
	char	*line;

	line = map_in_line(map, fd);
	map->map_tab = ft_split(line, '\n');
	map->dup = ft_split(line, '\n');
	free(line);
}

int	check_map(char *ber, t_map *map)
{
	int	fd;

	fd = open(ber, O_RDONLY);
	if (fd == -1)
		return (1);
	fill_map(map, fd);
	if (shape_map(map))
	{
		close(fd);
		free_tab(map, 1);
	}
	if (map->nbr_c < 1)
		return (close(fd),
			write(1, "Map need to have at least one collectible\n", 42), 1);
	if (map->nbr_p != 1)
		return (close(fd),
			write(1, "Map need to have one character\n", 32), 1);
	if (map->nbr_e != 1)
		return (close(fd),
			write(1, "Map need to have one exit\n", 26), 1);
	close(fd);
	return (0);
}
