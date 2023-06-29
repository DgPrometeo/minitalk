/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:34:31 by danielga          #+#    #+#             */
/*   Updated: 2022/12/23 12:23:44 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//									ITOA

/**
 * @brief Counts the number of digits in the integer value of the string. 
 * It will add +1 if the value is negative to add the '-'.
 * 
 * @param n The integer.
 * 
 * @return The number of cells the memory will have for the integer.
 **/
static int	ft_numberlen(long n)
{
	int	c;

	c = 0;
	if (n < 0)
	{
		c++;
		n = -n;
		ft_numberlen(n);
	}
	if (n == 0)
	{
		c++;
		return (c);
	}
	while (n > 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

/*
We create three variables: one to know the integer dimension, one to modify it 
to type 'long', and the memory reservation.
We calculate the dimension of the value with the function 'ft_numberlen' 
and create the memory reserve with the dimensions +1 for the null. We check 
that it has been created correctly, and we check if it is negative to introduce
in the first position the '-', passing the value to positive to continue.
We check if it is a '0' because if so, the first position would be 0 and we 
place the null in the next one to finish it. If it is greater than 0, in a loop
we will place in the memory each remainder of a division of 10 of the number to 
start from the end, adding '0/48' to turn it into a number. To advance in the 
loop, we will reduce the number by dividing it into 10 and subtracting its 
dimension to place them until the position reaches 0.
*/

char	*ft_itoa(int n)
{
	long	len;
	long	nmb;
	char	*str;

	nmb = (long)n;
	len = ft_numberlen(nmb);
	str = (char *)malloc(sizeof (char) * (len + 1));
	if (!str)
		return (NULL);
	if (nmb < 0)
	{
		str[0] = '-';
		nmb = -nmb;
	}
	if (nmb == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nmb > 0)
	{
		str[len] = nmb % 10 + 48;
		nmb = nmb / 10;
		len--;
	}
	return (str);
}
