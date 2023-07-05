/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:35:14 by danielga          #+#    #+#             */
/*   Updated: 2023/07/05 12:16:00 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhex(unsigned long p, char *hex)
{
	int		len;

	len = 0;
	if (p == 0)
		return (ft_printchar('0'));
	if (p > 15)
	{
		len += ft_printhex(p / 16, hex);
		len += ft_printhex(p % 16, hex);
	}
	else
		len += ft_printchar(hex[p % 16]);
	return (len);
}
