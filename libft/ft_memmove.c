/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:45:05 by danielga          #+#    #+#             */
/*   Updated: 2022/12/23 13:02:52 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									MEMMOVE
We pass the two variables to 'char *' and create a counter. Now, there are two
options: if the function 'dst' is larger than the function 'src', we will loop 
through it until the counter reaches 'len' and copy it cell by cell. 
If 'src' is larger than 'dst', we will loop with the counter at 'len' and copy
'src' before the first position of 'dst' until the counter reaches 0.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*str;
	char	*ps;

	i = 0;
	str = (char *)dst;
	ps = (char *)src;
	if (!dst && !src)
		return (0);
	if (str > ps)
	{
		while (len-- > 0)
		{
			str[len] = ps[len];
		}
	}
	else
	{
		while (i < len)
		{
			str[i] = ps[i];
			i++;
		}
	}
	return (dst);
}
