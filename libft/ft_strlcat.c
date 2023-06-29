/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:30:46 by danielga          #+#    #+#             */
/*   Updated: 2022/12/27 10:32:43 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									STRLCAT
We create two counters and a 'char *' to replace the 'const char *src' so we 
can modify it. We generate a loop in which we reach the null of 'dst' as long 
as it is smaller than the 'size' given in the function. If we finish the 'dst' 
we proceed to enter in 'dst' the new 'src' in the sum of the counter of 'dst' 
with the new counter as long as it is less than the 'size'. If it reaches the 
end of the string and still does not reach the 'size' we proceed to place 
nulls in the following positions. We return the 'ft_strlen' function of 'src'
+ the first counter of 'dst'.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*ps;

	ps = (char *)src;
	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < size)
	{
		i++;
	}
	while (ps[j] != '\0' && (i + j + 1) < size)
	{
		dst[i + j] = ps[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (ft_strlen(ps) + i);
}
