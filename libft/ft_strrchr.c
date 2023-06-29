/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:56:44 by danielga          #+#    #+#             */
/*   Updated: 2022/12/27 18:01:49 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*									STRRCHR
We create a counter that will have the dimension of the string thanks to the 
function 'ft_strlen', we also create a string that replaces the one given by 
'char *' and an auxiliary 'char' that will replace the integer 'c'. 
To go through the string until we reach the first position that matches from 
the end, we create a loop in which the counter will go down to 0 and if it 
finds a position that matches 'c' it will return the address of the position 
of that character. If it runs through the entire loop and does not find it, it 
will exit the loop and return null.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	x;
	int		i;
	char	*str;

	i = ft_strlen(s);
	str = (char *)s;
	x = (char) c;
	while (i >= 0)
	{	
		if (str[i] == x)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
