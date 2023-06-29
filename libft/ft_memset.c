/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:38:28 by danielga          #+#    #+#             */
/*   Updated: 2022/12/23 13:07:46 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									MEMSET
We convert the memory into an 'unsigned char *' and create a counter. We create 
a loop that goes through the memory from the position indicated in 'len' to 0. 
Inside, we will copy in each cell the character 'c' and subtract 'len'. finally
we return the converted memory to 'void *'.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = b;
	while (len > 0)
	{
		str[i] = c;
		len--;
		i++;
	}
	return ((void *)str);
}
