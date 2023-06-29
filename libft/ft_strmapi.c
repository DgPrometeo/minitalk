/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:00:50 by danielga          #+#    #+#             */
/*   Updated: 2022/12/23 13:39:10 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									STRMAPI
We create a function that generates a malloc and inside each cell places the 
delivered function. 
First we consider if we have been given the elements to exercise the function. 
Then we calculate the dimension of the string and we generate the reservation 
with malloc +1 once verified that it has been created, we generate a counter 
that begins in 0 and cell by cell we copy the function  with the two variables 
that tell us, the counter and the same position of the  counter and the same 
position of the string. finally we place in the last  position the null position 
the null and return the memory.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(sizeof (char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
