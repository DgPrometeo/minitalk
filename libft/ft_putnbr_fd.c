/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:07:02 by danielga          #+#    #+#             */
/*   Updated: 2022/12/23 13:36:52 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*								PUTNBR_FD
First we consider whether the given number is the minimum number of an integer.
To correct this step, we do an 'ft_putchar_fd' of '-2', so that it is already 
lower and we can work with the number more easily by doing recursion. 
Then we check if it is a negative number. If so, we do an 'ft_putchar_fd'
of '-' and we pass the number to positive and do recursion. Once it is positive
we will divide and store the remainder with recursion until it is less than 10 
to be able to 'ft_putchar_fd' the digit by digit.
*/

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}
