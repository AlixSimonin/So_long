/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:37:22 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/17 16:26:04 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_data	var;

	ft_memset(&var, 0, sizeof(var));
	if (ac != 2 || check_arg(av[1]) == 0)
	{
		ft_printf("Invalid argument, please input a map.ber\n");
		exit(1);
	}
	game(&var);
}