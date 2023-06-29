/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:46:47 by danielga          #+#    #+#             */
/*   Updated: 2022/12/27 10:14:34 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									STRITERI
We create a counter and create an integer with which to have the dimension of 
the string with the function 'ft_strlen'. The process followed is to create a 
loop in which the given function is executed with the parameters of the counter 
and the address of the string in the position of the counter until the whole 
string is covered and add the null in the last position. 
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	size_t			len;

	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}
