/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:05:03 by danielga          #+#    #+#             */
/*   Updated: 2022/12/27 17:47:52 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*								STRNCMP
We create a counter that will loop through the two strings. In a loop, the 
counter will loop through the strings until they are null or reach the number 
specified in the function, 'n'. In it, if it finds a difference between the two 
strings, it will give the result of the subtraction of both strings at their 
current position.
If the counter exits the loop without finding a difference, it will return 
the subtraction.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] && s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		}
		i++;
	}
	if (i != n)
	{
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	}
	return (0);
}
