/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:10:59 by asimonin          #+#    #+#             */
/*   Updated: 2023/01/10 17:53:39 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uns_int_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_uns_itoa(unsigned int nbr)
{
	int			len;
	char		*str;

	len = uns_int_len(nbr);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (nbr != 0)
	{
		str[len - 1] = (nbr % 10) + 48;
		nbr /= 10;
		len--;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int nbr)
{
	int		len;
	char	*num;

	if (nbr == 0)
		len = write(1, "0", 1);
	else
	{
		num = ft_uns_itoa(nbr);
		len = ft_print_str(num);
		free (num);
	}
	return (len);
}
