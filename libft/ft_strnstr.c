/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:05:40 by danielga          #+#    #+#             */
/*   Updated: 2022/12/27 17:57:26 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									STRNSTR
We create two counters, and check that the 0 position of 'needle' has something,
if there is nothing it should return 'haystack' converted to 'char *'. We 
create a loop in which we will loop through the 'haystack' until the counter
reaches 'len'. Once inside, if 'haystack' and 'needle' coincide, it will enter
another loop until the sum of the counters is greater than 'len' and 
'haystack'in the position of the counters added is similar to 'needle', it 
will go through the string until there is no 'needle', when there is not, 
we will return the address of the position 'haystack' converted into a 'char *'.
If any element fails, it will return 0.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (i + j < len && haystack[i + j] == needle[j])
			{
				j++;
				if (!needle[j])
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (0);
}
