/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:15:22 by danielga          #+#    #+#             */
/*   Updated: 2022/12/27 17:41:58 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									STRLCPY
We create a counter, an integer that is the size of 'src' with the 'ft_strlen' 
function, and a 'char *' to replace the 'const char *src'. The first thing we 
check is if the 'dstsize' is greater than 0 so we can continue. If it is 
correct, we create a loop in which it will be maintained until the string of 
'src' reaches null or the counter is greater than the size of 'dstsize' minus 
one to count the null. Inside, the information from 'src' will be copied into 
'dst', finishing by adding the null. 
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	aux;
	char	*ps;

	ps = (char *)src;
	aux = ft_strlen(src);
	if (dstsize == 0)
		return (aux);
	else
	{
		i = 0;
		while (ps[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = ps[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (aux);
}
