/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:37:47 by asimonin          #+#    #+#             */
/*   Updated: 2023/01/10 17:53:10 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(const char type, va_list arg)
{
	int	len;
	int	n;

	len = 0;
	n = 1;
	if (type == 'c')
		len = ft_print_char(va_arg(arg, int));
	else if (type == 's')
		len = ft_print_str(va_arg(arg, char *));
	else if (type == 'p')
		len = ft_print_void(va_arg(arg, unsigned long), "0123456789abcdef", n);
	else if (type == 'd' || type == 'i')
		len = ft_print_nbr(va_arg(arg, int));
	else if (type == 'u')
		len = ft_print_unsigned(va_arg(arg, unsigned int));
	else if (type == 'x')
		len = ft_print_hexa(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		len = ft_print_hexa(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (type == '%')
		len = ft_print_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	arg;

	len = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_conversion(str[i + 1], arg);
			i++;
		}
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
