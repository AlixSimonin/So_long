/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:44:25 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/15 19:49:18 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_arg(char *av)
{
	char	*s;

	s = ft_strnstr(av, ".ber", ft_strlen(av));
	if (!s || ft_strlen(s) != 4)
		return (1);
	return (0);
}