/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:52:14 by danielga          #+#    #+#             */
/*   Updated: 2023/07/05 12:16:03 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
	{
		ft_printstr("-2147483648");
		return (11);
	}
	else if (n < 0)
	{
		len += ft_printchar('-');
		len += ft_printnbr(-n);
	}
	else if (n > 9)
	{
		len += ft_printnbr(n / 10);
		len += ft_printnbr(n % 10);
	}
	else
		len += ft_printchar(n + 48);
	return (len);
}
