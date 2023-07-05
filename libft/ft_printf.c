/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:50:01 by danielga          #+#    #+#             */
/*   Updated: 2023/07/05 12:15:56 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_variable(va_list args, char const str)
{
	int		len;
	char	*hex;

	len = 0;
	hex = "0123456789abcdef";
	if (str == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (str == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (str == 'p')
	{
		len += ft_printstr("0x");
		len += ft_printhex(va_arg(args, unsigned long), hex);
	}
	else if (str == 'd' || str == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (str == 'u')
		len += ft_print_unsig_nbr(va_arg(args, unsigned int));
	else if (str == 'x')
		len += ft_printhex(va_arg(args, unsigned int), hex);
	else if (str == 'X')
		len += ft_printhex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (str == '%')
		len += ft_printchar('%');
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	len = 0;
	i = 0;
	va_start (args, str);
	if (write(1, "", 0) == -1)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_variable(args, str[i]);
		}
		else
		{
			len += ft_printchar(str[i]);
		}
		i++;
	}
	va_end (args);
	return (len);
}
