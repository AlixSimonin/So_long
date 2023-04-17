/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:10:13 by asimonin          #+#    #+#             */
/*   Updated: 2023/01/10 17:53:17 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_void(unsigned long ptr, char *base, int position)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (position)
		len += write(1, "0x", 2);
	if (ptr > 15)
	{
		len += ft_print_void(ptr / 16, base, 0);
		len += ft_print_char(base[ptr % 16]);
	}
	else
		len += ft_print_char(base[ptr]);
	return (len);
}
