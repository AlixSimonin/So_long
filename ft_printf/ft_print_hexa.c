/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:08:13 by asimonin          #+#    #+#             */
/*   Updated: 2023/01/10 17:54:04 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr > 15)
	{
		len += ft_print_hexa(nbr / 16, base);
		len += ft_print_char(base[nbr % 16]);
	}
	else
		len += ft_print_char(base[nbr]);
	return (len);
}
