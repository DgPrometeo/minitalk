/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:51:57 by danielga          #+#    #+#             */
/*   Updated: 2022/12/23 12:50:11 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									MEMCMP
First, we transform the strings to unsigned char as indicated by the man. Then,
we create a counter to scroll through the memories in a loop.  If we find a 
difference between 's1' and 's2' we return the subtraction directly.
If the counter has reached n and no difference has been found, than from 
the subtraction between 's1' and 's2'.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *) s1;
	ss2 = (unsigned char *) s2;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	if (i != n)
	{
		return (ss1[i] - ss2[i]);
	}
	return (0);
}
