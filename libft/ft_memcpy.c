/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:42:34 by danielga          #+#    #+#             */
/*   Updated: 2022/12/23 12:56:59 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									MEMCPY
To carry out the function we pass the two memories to 'char *' and create a 
counter; if any of them is missing we must give '0'. If they are, we make a 
loop in which it will exit when 'n' reaches 0. inside we will copy 'src' in 
'dst' and moving with the counter in the two memories to copy them completely. 
Finally we return the modified dst.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*c;
	char	*d;

	i = 0;
	c = (char *)src;
	d = (char *)dst;
	if (!dst && !src)
		return (0);
	while (n > 0)
	{
		d[i] = c[i];
		i++;
		n--;
	}
	return (dst);
}
