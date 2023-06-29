/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:08:17 by danielga          #+#    #+#             */
/*   Updated: 2022/12/27 10:06:25 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*								STRCHR
We create a string that is 'char *', a counter and a 'char' that is the 
character 'c' that the function gives us. We loop through the string until it 
finds the character and then it will return the address of the position in the
string where it is located. If it does not find it and terminates the string,
it will exit returning 0 inside the loop itself.
*/

char	*ft_strchr(const char *s, int c)
{
	char	x;
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	x = (char) c;
	while (s[i] != x)
	{	
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (&str[i]);
}
