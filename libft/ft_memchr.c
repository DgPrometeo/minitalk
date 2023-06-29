/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:32:55 by danielga          #+#    #+#             */
/*   Updated: 2022/12/23 12:46:30 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									MEMCHR
With a variable as counter and a variable to modify 's', we traverse 'n' until
 we find 'c'. If found, returns the position where it is located.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (0);
}
